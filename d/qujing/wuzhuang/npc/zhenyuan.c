// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zhenyuan.c...weiqi, 98.02.24.
// copied a lot of useful functions from "rulai.c"...thanks snowcat:)

#define DEBUG 0

inherit NPC;

string asked_guo(object me);

void create()
{
   set_name("镇元大仙", ({"zhenyuan daxian", "zhenyuan", "daxian"}));
   set("title", "地仙之祖");
   set("gender", "男性" );
   set("age", 65);
   set("per", 24);
   set("str", 30);
   set("long", "交游遍三界，桃李漫五行。好一位地仙之祖！\n");
   set("class", "xian");
   set("combat_exp", 2800000);
   set("attitude", "peaceful");
   set("rank_info/respect", "观主");
   set_skill("unarmed", 180);
   set_skill("wuxing-quan", 200);
   set_skill("dodge", 150);
   set_skill("baguazhen", 160);
   set_skill("parry", 180);
   set_skill("sword", 160);
   set_skill("sanqing-jian", 190);
   set_skill("staff", 160);
   set_skill("qixing-zhang", 190);
   set_skill("hammer", 160);
   set_skill("kaishan-chui", 190);
   set_skill("force", 180);   
   set_skill("zhenyuan-force", 180);
   set_skill("literate", 180);
   set_skill("spells", 200);
   set_skill("taiyi", 200);
   set_skill("rootshentong", 200);
   map_skill("spells", "rootshentong");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "sanqing-jian");
   map_skill("dodge", "baguazhen");
   map_skill("staff", "qixing-zhang");
   map_skill("hammer", "kaishan-chui");

   set("max_kee", 4500);
   set("max_sen", 4500);
   set("force", 5000);
   set("max_force", 2500);
   set("mana", 7000);
   set("max_mana", 3500);   
   set("force_factor", 100);
   set("mana_factor", 150);

   set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
   set("chat_chance_combat", 60);
   set("chat_msg_combat", 
   ({
     //(: cast_spell, "zhenhuo" :),
     (: cast_spell, "qiankun" :),
   }) );

   set("inquiry", ([
     "name": "老夫镇元子。\n",
     "here": "这里是五庄观，不过住的可不是道士。\n",
     "人参果": (: asked_guo :),
   ]) );

   setup();
   carry_object("/d/obj/cloth/xianpao")->wear();
   carry_object("/d/obj/weapon/sword/ruler")->wield();
}

void init()
{
   add_action("do_back", "back");
}

//the following is for renshen dahui...

void announce (object me, string str)
{
   if (DEBUG)
   { 
     object weiqi = find_player ("weiqi");
     if (weiqi && wizardp(weiqi))
        tell_object (weiqi,"◆ "+str+"\n");
   }
   else
   {
     CHANNEL_D->do_channel(me,"chat",str);
   }
}

void start_renshen()
{
   object me;

   me = this_object();
    
   set_temp("invite","public");

   announce (me, "五庄观人参果品尝大会即将开始！\n");
   announce (me, "诸位仙贤如愿观礼，使accept zhenyuan daxian便可！\n");
   remove_call_out ("inviting");
   call_out ("inviting",1,me);

   call_out("ready1", 180);
   set_temp("ready0", 1);
}

void ready1()
{
   object me;

   me = this_object();

   announce (me, "五庄观人参果品尝大会马上就要开始！\n");
   announce (me, "诸位仙贤如愿观礼，使accept zhenyuan daxian便可！\n");
   call_out("ready2", 180);
   set_temp("ready1", 1);
}

void ready2()
{
   object me;

   me = this_object();

   announce (me, "五庄观人参果品尝大会现在开始！\n");
   announce (me, "诸位仙贤如愿观礼，使accept zhenyuan daxian便可！\n");
   set_temp("ready2", 1);
}

string asked_guo(object me)
{ 
   int i, total;
   object guo;
   object *inv ;
      
   me=this_player();

   //if no renshenguo party at all...
   if( query_temp("ready0") != 1 ) return ("人参果可是个好东西。\n");

   //if not in the right place, no guo...
   //need the right name, also right outdoors(so ppls can not use fake room).
   if( (environment(this_object()))->query("short") != "人参果园" || 
     (environment(this_object()))->query("outdoors") != "wuzhuang" )
   {
     return ("这里又不是果园，哪来的人参果。\n");
   }

   //if waiting for ppls...
   if( query_temp("ready1") != 1 ) return ("不要急，再等等。\n");

   //if ready to begin...
   if( query_temp("ready2") != 1 ) return ("不要急，马上就有。\n");

   //if finished...
   if( query_temp("finished") == 1 ) return ("人参果已分发完了。\n");

   //now check how many people here...
   total = 0;
   inv = all_inventory( environment(this_object()) );
   for(i=0; i<sizeof(inv); i++)
   {
     if( userp(inv[i]) && (!wizardp(inv[i]))  ) total++;
   }

   if( total > 3 ) return ("哎呀！这么多人，现在只有三枚成熟的人参果。\n");
   else if ( total <= 3 && total > 0 )
   {
     for(i=0; i<sizeof(inv); i++)
     {
        if( userp(inv[i]) && (!wizardp(inv[i]))  ) 
        {//wiz not counted...
          guo = new("/d/obj/drug/renshen-guo");
          guo->move(inv[i]);
          message_vision("$N给$n一枚人参果。\n", this_object(), inv[i]);
          announce (this_object(), "恭喜恭喜！" + inv[i]->query("name") + "获得人参果一枚。\n");
        }
     }

     set_temp("finished", 1);
     call_out("finishing", 5);

     return ("好！人参果分发完毕，诸位仙贤尽情享用吧。\n");
   }
   else return ("谁要人参果？\n");
   
}

void finishing()
{
   message_vision("$N哈哈大笑几声，顿时无影无踪了。\n", this_object());
   delete_temp("invite");//this is necessary if not going to destruct this obj.
   destruct(this_object());
}

void inviting (object me)
{
   int i;
   object *list;

   if (! me->query_temp("invite"))
   return;
  
   remove_call_out ("inviting");
   call_out ("inviting",4+random(4),me);

   list = users();
   i = sizeof(list);
   while  (i--)
   {
     string here, there;

     reset_eval_cost();
    
     if (!environment(list[i]))
        continue;
    
     if (environment(list[i])->query("unit")) // not a room
        continue;
   
     if (list[i]->is_fighting())
        continue;
    
     if (list[i]->is_busy())
        continue;
    
     if (list[i]->query_temp("no_move"))
        continue;
    
     if (!living(list[i]))
        continue;
    
     if ((string)list[i]->query_temp("accept")!=me->query("id"))
        continue;

     list[i]->set_temp("accept",0);
     here = (string)environment(me);
     there = (string)environment(list[i]);
     if (here == there)
        continue;

     message_vision("$N的大袖往外一罩…\n",me);
     list[i]->set_temp("accept",0);
     list[i]->set_temp("wzg/from",there);

     message_vision("一团祥云飘来，云中伸出一只巨大的衣袖将$N轻轻一罩，消失在天空。\n",list[i]);
         list[i]->move(here);
     message_vision("…$N大袖轻轻一抖，$n滑了出来。\n",me,list[i]);
     break;
   }
}

int do_back(string arg)
{
   object who = this_player();
   object me = this_object();
   string here = (string)environment(me);
   string there = who->query_temp("wzg/from");

   message_vision("$N请求$n送$N回返。\n",who,me);
 
    //if (!there)
   // there = "/d/city/kezhan";
   there = "/d/city/kezhan";

   who->set_temp("accept",0);
   message_vision("$N的大袖朝着$n轻轻一罩…\n",me,who);
   who->move(there);
   message_vision("…云中伸出一只巨大的衣袖轻轻一抖，只见$N从里面滑了出来。\n",who);
  
   return 1;
}


