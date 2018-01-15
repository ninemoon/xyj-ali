// sgzl

inherit NPC;

string *names = ({
  "黄莺侍儿",
  "黄鹂侍儿",
  "黄雀侍儿",
});

void create()
{
    set_name(names[random(sizeof(names))], ({"shi er", "shier"}));
    set("gender", "女性");
    set("title", "侍卫");
    set("age", 16);
    set("long", "孔雀公主门下侍卫。\n");
    set("class", "yaomo");
    set("combat_exp", 25000);

    set("attitude", "peaceful");
    create_family("大雪山", 4, "弟子");
    set_skill("unarmed", 20);
    set_skill("dodge", 20);
    set_skill("parry", 20);
    set_skill("sword", 20);
    set_skill("avian-sword", 10);
    set_skill("peripateticism", 20);
    set_skill("force", 20);   
    set_skill("iceblood-force", 20);
    map_skill("force", "iceblood-force");
    map_skill("sword", "avian-sword");
    map_skill("dodge", "peripateticism");

    set("per", 21);
    set("max_kee", 300);
    set("max_sen", 300);
    set("force", 300);
    set("max_force", 120);
    set("force_factor", 2);
    setup();

    set("nkgain", 20);

    carry_object("/d/obj/cloth/skirt")->wear();
    carry_object("/d/obj/cloth/shoes")->wear();
    carry_object("/d/obj/weapon/sword/peijian")->wield();
    carry_object("/d/obj/weapon/throwing/yinzhen");

    setup();
}
