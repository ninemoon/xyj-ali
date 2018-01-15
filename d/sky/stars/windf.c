//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("野风信子",({"star windf","windf","star"}));
  set("gender", "女性");
  set("title", "娄金星官");
  set("age", 38);

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 2143726);
  set("kee", 1346);
  set("max_kee", 1346);
  set("sen", 2472);
  set("max_sen", 2472);
  set("force", 6641);
  set("max_force", 3321);
  set("mana", 10099);
  set("max_mana", 5050);
  set("force_factor", 168);
  set("mana_factor", 253);
  set("str", 14);
  set("per", 19);

setup();
carry_object("/obj/loginload/skirt.c")->wear();
carry_object("/obj/loginload/shoes.c")->wear();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();
}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name","杏花枝");
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","绿叶");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name","花瓣");
}
