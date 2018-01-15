//sgzl

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("青青",({"star ivan","ivan","star"}));
  set("gender", "女性");
  set("title", "通风大圣");
  set("age", 43);
  set("long", "    \n爱,认真就好\n别急着实现那些别人说的\n天荒地老\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 4342951);
  set("kee", 1360);
  set("max_kee", 1360);
  set("sen", 2725);
  set("max_sen", 2725);
  set("force", 6499);
  set("max_force", 3250);
  set("mana", 10959);
  set("max_mana", 5480);
  set("force_factor", 150);
  set("mana_factor", 275);
  set("str", 16);
  set("per", 23);

setup();
carry_object("/obj/loginload/skirt.c")->wear();
carry_object("/obj/loginload/shoes.c")->wear();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/waist")->wear();
carry_object(__DIR__"obj/pifeng")->wear();
}

void init()
{
  object me=this_object();
  object my_weapon,my_armor1,my_armor2;
  string weapon_id="sword";
  string armor1_id="waist",armor2_id="pifeng";
  ::init();
  if (my_weapon=present(weapon_id, me))
       my_weapon->set("name",HIY"青女剑"NOR);
  if (my_armor1=present(armor1_id, me))
       my_armor1->set("name",HIY"吹笳明月带"NOR);
  if (my_armor2=present(armor2_id, me))
       my_armor2->set("name",HIY"倚剑白云衣"NOR);
}

