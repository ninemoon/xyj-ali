//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("使者",({"star amao","amao","star"}));
  set("gender", "男性");
  set("title", "鬼金星官");
  set("age", 59);

  set("attitude", "heroism");
  set("class", "yaomo");
  set("combat_exp", 2197634);
  set("kee", 1307);
  set("max_kee", 1307);
  set("sen", 2409);
  set("max_sen", 2409);
  set("force", 5815);
  set("max_force", 2908);
  set("mana", 9859);
  set("max_mana", 4930);
  set("force_factor", 144);
  set("mana_factor", 247);
  set("str", 29);
  set("per", 11);

setup();
carry_object("/obj/loginload/linen.c")->wear();
carry_object(__DIR__"obj/blade")->wield();
carry_object(__DIR__"obj/armor")->wear();
carry_object(__DIR__"obj/pifeng")->wear();
}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="blade";
  string armor1_id="armor",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"血淋淋的枯骨"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name","人皮");
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"头盖骨"NOR);
}

