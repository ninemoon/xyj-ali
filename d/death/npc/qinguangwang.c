inherit __DIR__"difushiwang.c";

void create()
{
    set_name("秦广王", ({"qinguang wang", "wang", "qinguang"}));
    set("title", "阴间十王之");
    set("gender", "男性");
    set("age", 60);
    set("class", "ghost");
    set("attitude", "friendly");
    set("shen_type", 1);
    set("per", 30);
    set("max_kee", 800);
    set("max_gin", 800);
    set("max_sen", 800);
    set("force", 850);
    set("max_force", 800);
    set("force_factor", 60);
    set("max_mana", 800);
    set("mana", 1000);
    set("mana_factor", 30);
    set("combat_exp", 800000);
    set_skill("unarmed", 140);
    set_skill("dread-hand", 120);
    set_skill("dodge", 140);
    set_skill("parry", 140);
    set_skill("necromancy", 100);
    set_skill("tonsillit", 100);
    set_skill("spells", 120);
    set_skill("force", 120);
    set_skill("ghost-steps", 100);
    map_skill("dodge", "ghost-steps");
    map_skill("unarmed", "dread-hand");
    map_skill("force", "tonsillit");
    map_skill("spells", "necromancy");
    create_family("阎罗地府", 2, "你好");
    setup();
    
    carry_object("/d/obj/cloth/mangpao")->wear();
    //        carry_object("/d/lingtai/obj/shoe")->wear();
    //        carry_object("/d/lingtai/obj/putibang")->wield();
}
void attempt_apprentice(object ob, object me)
{
    if (((int)ob->query("combat_exp") < 50000)) {
        command("say " + RANK_D->query_rude(ob) + "功底如此之差，不配做我徒弟！");
        return;
    }
    command("haha");
    command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
    command("recruit " + ob->query("id") );
    return;
}
int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "ghost");
}

