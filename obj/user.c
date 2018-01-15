// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// user.c

#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_BACKUP;
inherit F_ENCODING;

static int last_age_set;

void create()
{
   ::create();
   set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
   set_temp("terminal_type", term_type);
   message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}

void reset()
{
   if( (int)query("potential") - (int)query("learned_points") < 100 )
     add("potential", 1);
   if( (int)query("thief") > 0 )
     add("thief", -1 );
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
   string id;

   id = query("id", 1);
   if( !id ) id = geteuid();
   if( !id ) id = getuid();
   if( !stringp(id) ) return 0;
   return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

// save(1) will only save player data, do not touch autoload.
// used by /feature/vendor_sale.
// normal save should use save() or save(0).
// mon 5/12/98
int save(int raw)
{
   int res;

   if(!raw) save_autoload();
   res = ::save();
   if(!raw) clean_up_autoload();     // To save memory
   return res;
}

int backup()
{
   int res;

   save_autoload();
   res = ::backup();
   clean_up_autoload();     // To save memory
   return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
    // Update the time we spend on mudding, using method from TMI-2 mudlib.
    if (!last_age_set) last_age_set = time();
    add("mud_age", time() - last_age_set);
    last_age_set = time();
    set("age", 14 + (int)query("age_modify")/86400 + (int)query("mud_age")/ 86400);
    // fake_age is set as the age when player gets dao-xing:不堕轮回。
    // so later on, he/she always looks like the age of that time:)
    // NewX move it from /cmds/std/look.c
    if (!query("always_young") && query("combat_exp") > 729000) {
        set("always_young", 1);
        set("fake_age", query("age"));
    }
}

void load_fabao(string type, int i)
{
    int series_no = query("fabao/" + type + i);
    object newob = new("/obj/fabao");
    
    if (!series_no || !newob)
        return;

    newob->set("owner_id", query("id"));
    newob->set("series_no", series_no);
    if (!newob->restore()) {
        tell_object(this_object(), "不能 restore fabao. \n");
        destruct(newob);
        return;
    }

    seteuid(query("id"));
    export_uid(newob);
    seteuid(getuid());

    newob->setup();

    newob->save();
    newob->move(this_object());
    newob->wield();
    newob->wear();
}

void setup()
{
    // We want set age first before new player got initialized with
    // random age.
    update_age();

    ::setup();
    restore_autoload();

    if (!mapp(query("fabao"))) {
        object cloth;
        if (query("gender") == "女性") {
            cloth = new("/obj/loginload/skirt");
            cloth->move(this_object());
            cloth->wear();
            cloth = new("/obj/loginload/shoes");
            cloth->move(this_object());
            cloth->wear();
        } else {
            cloth = new("/obj/loginload/linen");
            cloth->move(this_object());
            cloth->wear();
        }
    }
    else {
        // here We restore the self-made fabao
        int i, count = sizeof(query("fabao"));
        for (i = count - 1; i > 0; i--)
            load_fabao("armor", i);
        for (i = count - 1; i > 0; i--)
            load_fabao("weapon", i);
    }
}

private void user_dump(int type)
{
   switch(type) {
     case DUMP_NET_DEAD:
        tell_room( environment(), query("name") + "断线超过 "
          + NET_DEAD_TIMEOUT/60 + " 分钟，自动退出这个世界。\n");
        command("quit");
        break;
     case DUMP_IDLE:
           if(!wizardp(this_object())){
        tell_object( this_object(), "对不起，您已经发呆超过 " 
          + IDLE_TIMEOUT/60 + " 分钟了，请下次再来。\n");
        tell_room( environment(), "一阵风吹来，将发呆中的" + query("name")
          + "化为一堆飞灰，消失了。\n", ({this_object()}));
        command("quit");
                      }
                 break;
     default: return;
   }
}

// net_dead: called by the gamedriver when an interactive player loses
// his network connection to the mud.
private void net_dead()
{
   object link_ob;

   set_heart_beat(0);
   if( objectp(link_ob = query_temp("link_ob")) )  {

     if(!link_ob->is_character()) {
       link_ob->set("last_on", time());
       link_ob->set("last_from", query_ip_name(this_object()));
       link_ob->save();
     }
     destruct(link_ob);
        }

   // Stop fighting, we'll be back soon.
   add_netdead_enemy();
   remove_all_enemy();

   set_temp("netdead", 1);
   if( userp(this_object()) ) {
       call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
       if (!this_object()->query("env/invisibility"))
           tell_room(environment(), query("name") + "断线了。\n", this_object());
       CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
   } else {
     command("quit");
   }
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
   set_heart_beat(1);
   set_temp("netdead",0);
   remove_netdead_enemy();
   remove_call_out("user_dump");
   tell_object(this_object(), "重新连线完毕。\n");
}

