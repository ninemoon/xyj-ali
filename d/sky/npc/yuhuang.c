//modified by vikee
//2000.10

#include <ansi.h>
inherit NPC;

int promote_me();
int ask_pantao();
int do_huoyan(object);

void create()
{
    set_name("��ʴ��", ({"yuhuang dadi", "yuhuang", "dadi", "yudi", "king"}));
    set("gender", "����");
    set("title", "�칬֮��");
    set("age", 45);
    set("long", "    \n����������޳֣�������һǧ�߰���ʮ�ٵ���ʴ�ۡ�\n");

    set("attitude", "peaceful");
    set("class", "xian");
    set("combat_exp", 4000000);
    set("kee", 2200);
    set("max_kee", 2200);
    set("sen", 2200);
    set("max_sen", 2200);
    set("force", 1200);
    set("max_force", 1200);
    set("mana", 2500);
    set("max_mana", 2500);
    set("force_factor", 0);
    set("mana_factor", 0);
    set("per", 30);
    set("kar", 30);

    set_skill("literate", 160);
    set_skill("sword", 80);
    set_skill("sanqing-jian", 40);
    set_skill("spells", 100);
    set_skill("force", 40);

    map_skill("sword", "sanqing-jian");

    set("inquiry", ([
        "here"   : "��������ҵ���������",
        "name"   : "�����������ɣ��治����أ�",
        "��ְ": (:promote_me :),
        "position": (:promote_me :),
    "pantao": (: ask_pantao :),
    "���԰":(:ask_pantao:),
    ]));

    setup();

carry_object("/d/obj/cloth/mangpao")->wear();
add_money("gold", 10);
}

int promote_me() 
{
    object me=this_object();
    object who=this_player();
     if (who->query("daoxing")<50000)  {
     message_vision("��ʴ�۲�м����Ц������������"+RANK_D->query_rude(who)+"����֪��ߵغ�\n",who);
     message_vision("ƾ����㱾�£�Ҳ�����칬���٣�\n",who);
     message_vision("��ʴ�ۺȵ��������ģ����������ҹ������\n",who);
     call_out ("throws1", 1,who);
     return 1;
    }
    else if (who->query("dntg/bmw")=="done") 
    {
     message_vision("���̾����"+RANK_D->query_respect(who)+"����Ը�������£������칬��Ҳû�б��ְλ��"+RANK_D->query_respect(who)+"������ı�߾Ͱɣ�\n",who);
     return 1;
    } 
    else if (objectp(present("wuqu xingjun", environment(me))))
    {
     message_vision("�Ա�ת�������Ǿ�������������칬�����������������������ٹ٣�ֻ��������ȱ�����ù��¡���\n",who);
     message_vision("��۵��˵�ͷ˵�������ͳ��������������¡��ա���\n",who);
     who->set("dntg/bmw", "allow");
     return 1;
    }
    else 
    {
     message_vision("��۵��˵�ͷ˵������"+RANK_D->query_respect(who)+"�Ժ���Ҳ鿴�Ǵ�������ְ����\n",who);
     return 1;
    }
}

void throws1 (object who)
{
    message_vision("ֻ��������������������ʿ�����ְ˽ŵ�����$N���˳�ȥ��\n",who);
    who->move("/d/dntg/sky/qianyuangong");
    tell_room(environment(who),"ֻ��"+who->query("name")+"���������ĵ����˳�����\n", ({who}));
    call_out ("throws2", 2,who);
}

void throws2 (object who)
{
    message_vision("������ʿ���һ������ȥ��$N���ӻ����½硣\n",who);
    who->move("/d/changan/bridge");
    tell_room(environment(who),"�����"+who->query("name")+"��ֱ��ˤ��������\n", ({who}));
}

void init()
{
   object yudi = this_object(),me = this_player();
   int dhg;

   if ((int)me->query("huoyan/tianwang_killed")>= 4  &&
            me->query("huoyan/bgl")=="done" &&
            me->query("huoyan/yudi")=="asked" &&
            me->query("huoyan/lingguan_killed") >=4  ) {
      command("chat* ��ʴ�ۡ�������һ��̾�˿�����");
      command("chat ���ˣ����ˣ�"+me->name()+"�����칬�ڽ�����������֣������Ҫ�����������ɣ�\n");
      command("chat* ��ʴ�۾��������ң��ѹ���̾�˿�����");
      command("chat ��ϲ"+ me->name()+"˳��ͨ�������칬�����ѹأ�");
      dhg  = 18000 + random(3000); 
      me->add("daoxing",dhg);
      me->set("danaotiangong", "done");
      me->set("dntg/bagualu", "done");
      me->delete("huoyan");
      tell_object(me,CYN"��Ӯ����"+COMBAT_D->chinese_daoxing(dhg)+"���С�\n"NOR);
      me->save();
   }

   if (me->query("dntg/bagualu")!="done" &&
      me->query("dntg/erlang")=="done" &&
          me->query("dntg/huaguo")=="done" &&
          me->query("dntg/donghai")=="done" &&
          me->query("dntg/bmw")=="done" &&
          me->query("dntg/lijing")=="done" &&
          me->query("dntg/laojun")=="done" &&
          me->query("dntg/yaochi")=="done" &&
          me->query("dntg/hell")=="done" &&
          me->query("dntg/pantao")=="done" &&
      me->query("huoyan/bgl") != "done")
   
   do_huoyan(me);
}

int do_huoyan(object me)
{
   object yudi = this_object();
   string door;
   command("chat " + me->name() + "������" + RANK_D->query_rude(me) + 
        "���½�ʱ�ŷ���������һ�����㡣\n");
   command("chat �������͵�ң�͵�ƣ�͵�ɵ��������ս����㣬�㻹�����翹��");
   command("chat ���ˣ����������ӽ�����¯�ж���������ʮ���գ���֮��Ϊ�ҽ���");
   message_vision("������������콫����$N�����������˳�ȥ��",me);
   door="/d/dntg/sky/nantian";
   door->set("dntg10", 1);
   me->set("huoyan/time", 2400+random(12 * (100-(int)me->query("kar"))));
   me->set("huoyan/yudi", "asked");
   tell_object(me,"��������һ�����㱻Ͷ������¯�С�\n");
   me->move("/d/dntg/doushuai/bgl1");
   me->set("startroom", "/d/dntg/doushuai/bgl1");
   me->save();
   return 1;
}

void die()
{
    if (environment())
    message("sound", "\nֻ����ʴ��������һ����������ң�\n", environment());

    set("eff_kee", 2200);
    set("eff_gin", 2200);
    set("eff_sen", 2200);
    set("kee", 2200);
    set("gin", 2200);
    set("sen", 2200);
    set("force", 1200);
    set("mana", 2500);
}

void unconcious()
{
    die ();
}

int ask_pantao() {
    object who=this_player();

    if (this_player()->query("dntg/pantao")=="done")
  {
    message_vision("$N�ݺݵص���$nһ�ۡ�\n",this_object(),this_player());
    command("say ����ȥ�����԰��û�Ŷ���");
    command("slogan "+this_player()->query("id"));
    return 1;
   }
    if (this_player()->query_temp("dntg/pantao")=="doing")
  {
    command("say �����Ѿ�����ȥ����԰���𣿻���ʲô��");
    return 1;
}
     if (who->query("daoxing")<50000)  {
     message_vision("��ʴ�۲�м����Ц������������"+RANK_D->query_rude(who)+"����֪��ߵغ�\n",who);
     message_vision("ƾ����㱾�£�Ҳ��ִ�����԰��\n",who);
     message_vision("��ʴ�ۺȵ��������ģ����������ҹ������\n",who);
     call_out ("throws1", 1,who);
     return 1;
  }
    if (who->query_temp("dntg/pantao")=="denied") {
    command("heng");
     command("say ˵���оͲ��У�����Ҳû�ã�");
     message_vision("��ʴ�ۺȵ��������ģ����������ҹ������\n",who);
     call_out ("throws1", 1,who);
     return 1;
  }
   command("hmm");
   command("consider");
   if (random(3)) {
     command("say �����˲��ɿ����ҿɲ����İ����԰������ܡ�");
     who->set_temp("dntg/pantao", "denied");
     return 1;
   }
    this_player()->set_temp("dntg/pantao", "doing");
    this_player()->set("dntg/pantao", "doing");
    message_vision("$N�������"+who->query("name")+"��"+RANK_D->query_rude(who)
                  +"���ţ�ֻ�»�����Щ�Ƿǡ�����Ҳ�ա�\n",this_object());
    command("ok "+this_player()->query("id"));
    command("say ������ȥ����ĸ��������԰�������鷳�úøɣ�");
    return 1;
}
