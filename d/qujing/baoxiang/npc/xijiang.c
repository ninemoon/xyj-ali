// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit NPC;
inherit F_VENDOR;

void create()
{
  set_name("锡匠", ({"xi jiang","jiang"}));
  set("gender", "男性");
  set("combat_exp", 1000);
  set("age", 35);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ([
        "xihu": "/d/qujing/baoxiang/obj/xihu",
        "xiwan": "/d/qujing/baoxiang/obj/xiwan",
        "xipen": "/d/qujing/baoxiang/obj/xipen",
      ]) );

  setup();
  carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
  add_money("silver", 15);
}
void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

