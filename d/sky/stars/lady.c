//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("方淑",({"star lady","lady","star"}));
  set("gender", "女性");
  set("title", "张月星官");
  set("age", 25);

  set("attitude", "heroism");
  set("class", "bonze");
  set("combat_exp", 2352571);
  set("kee", 1141);
  set("max_kee", 1141);
  set("sen", 2055);
  set("max_sen", 2055);
  set("force", 6113);
  set("max_force", 3057);
  set("mana", 8079);
  set("max_mana", 4040);
  set("force_factor", 153);
  set("mana_factor", 203);
  set("str", 20);
  set("per", 23);

setup();
carry_object("/obj/loginload/skirt.c")->wear();
carry_object("/obj/loginload/shoes.c")->wear();
carry_object(__DIR__"obj/staff")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/pifeng")->wear();
}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="staff";
  string armor1_id="waist",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","凌风翔");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","春欲暮");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name","秋水流");
}

