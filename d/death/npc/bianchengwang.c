inherit __DIR__"difushiwang.c";

void create()
{
    set_name("卞城王", ({"biancheng wang", "wang"}));
    set("title", "阴间十王之");
    set("gender", "男性");
    set("class", "ghost");
    set("age", 50);
    set("attitude", "friendly");
    set("per", 30);
    set("int", 30);
    set("max_kee", 800);
    set("max_gin", 600);
    set("max_sen", 600);
    set("force", 450);
    set("max_force", 400);
    set("force_factor", 40);
    set("max_mana", 1000);
    set("mana", 1000);
    set("mana_factor", 20);
    set("combat_exp", 600000);
    set_skill("spells", 119);
    set_skill("necromancy", 119);
    set_skill("unarmed", 119);
    set_skill("dodge", 119);
    set_skill("parry", 119);
    set_skill("force", 100);
    set_skill("tonsillit", 100);
    map_skill("force", "tonsillit");
    create_family("阎罗地府", 2, "你好");
    setup();

    carry_object("/d/obj/cloth/mangpao")->wear();
}

