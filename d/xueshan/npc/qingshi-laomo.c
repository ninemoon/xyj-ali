// qingshi-laomo.c...weiqi, 97.09.15.

inherit NPC;

void create()
{
    set_name("青狮老魔", ({"qingshi laomo", "qingshi", "laomo"}));
    set("title", "明王护法");
    set("gender", "男性" );
    set("age", 63);
    set("per", 112);//no rongmao description.

    set("long", "这位青狮老魔原来在狮驼山逍遥，跟大鹏明王颇有交情。\n"
        "后来狮驼山被方寸山三星洞的一位得道高人剿灭，\n"
        "老魔就投奔大鹏明王做了护法尊者。一个跟和尚有仇，\n"
        "一个跟道士有仇，也算是知交好友。\n");
    set("class", "yaomo");
    set("combat_exp", 800000);
    set("attitude", "peaceful");
    create_family("大雪山", 2, "弟子");
    set_skill("unarmed", 150);
    set_skill("pressheart-hand", 80);
    set_skill("dodge", 90);
    set_skill("peripateticism", 100);
    set_skill("parry", 70);
    set_skill("blade", 120);
    set_skill("ice-blade", 110);
    set_skill("force", 90);
    set_skill("iceblood-force", 90);
    set_skill("literate", 70);
    set_skill("spells", 90);
    set_skill("dengxian-dafa", 120);
    map_skill("spells", "dengxian-dafa");
    map_skill("force", "iceblood-force");
    map_skill("unarmed", "pressheart-hand");
    map_skill("blade", "ice-blade");
    map_skill("dodge", "peripateticism");

   set("max_kee", 1000);
   set("max_sen", 600);
   set("force", 1600);
   set("max_force", 800);
   set("mana", 1600);
   set("max_mana", 800);
   set("force_factor", 60);
   set("mana_factor", 25);

   set("eff_dx", -200000);
   set("nkgain", 400);

   set("cast_tuntian", -1);
   set("chat_chance_combat", 50);
   set("chat_msg_combat", ({
            (: cast_spell, "tuntian" :),
   }));

   setup();
   carry_object("/d/obj/armor/jinjia")->wear();
   carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{
    if ((string)ob->query("family/family_name") == "大雪山") {
        if ((int)ob->query("family/generation") < 2) {
            command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
        }
        else if ((int)ob->query("family/generation") == 2) {
            command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣你爷爷我了！\n");
        }
        else if ((int)ob->query("family/generation") == 3) {
            if ((string)ob->query("family/master_id") == "dapeng mingwang") {
                command("shake");
                command("say 不好，不好，我这还欠着大鹏的人情呢，怎么好抢他的徒弟。\n");
            } else {
                command(":D");
                command("say 你这个" + RANK_D->query_rude(ob) + "老换师父可不好！你师父也不是什么都不懂嘛...\n");
                command("recruit " + ob->query("id"));
            }
        } else {
            if ((int)ob->query("combat_exp") >= 50000) {
                command(":D ");
                command("say 好，" + RANK_D->query_respect(ob) + "好好跟我干，以后杀回狮驼山我请明王封你个巡山大将军！\n");
                command("recruit " + ob->query("id"));
            } else {
                command("say 你还是找鹦鹉，乌鸦他们先练着吧。\n");
            }
        }
    } else {
        command("hmm");
        command("say 这位" + RANK_D->query_respect(ob) + "，没有推荐人我可不能收你。\n");
    }

    return;
}

int recruit_apprentice(object ob)
{
    if (::recruit_apprentice(ob))
        ob->set("class", "yaomo");
}

void init()
{
    object ob = this_player();

    ::init();
    if ((string)ob->query("family/family_name")=="方寸山三星洞"
    &&  (int)ob->query("combat_exp")  >= 100000) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object ob)
{
    if (!ob || environment(ob) != environment()) return;

    switch (random(1)) {
        case 0:
            command("kick " + ob->query("id"));
            command("say 你这贼道好象还有两手，可敢跟你爷爷我斗一斗？");
            command("fight " + ob->query("id"));
            break;
    }
}

