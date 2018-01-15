// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit NPC;
inherit F_VENDOR;

void create()
{
  set_name("碧奴慕伊", ({"binu muyi", "muyi", "boss"}));
  set("gender", "女性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "hualan": "/d/obj/misc/hualan",
        "huaping": "/d/obj/misc/vase",
      ]) );

  setup();
  carry_object("/d/obj/cloth/nichang")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}
