inherit NPC;

void create()
{
    set_name("������ͷ", ({"jinjun jiaotou", "jiaotou"}));
    set("title", "������");
    set("gender", "����");
    set("age", 45);

    set("max_gin", 500);
    set("eff_gin", 500);
    set("gin", 500);
    set("max_kee", 500);
    set("eff_kee", 500);
    set("kee", 500);
    set("max_sen", 500);
    set("eff_sen", 500);
    set("sen", 500);

    set("combat_exp", 35000);

    set_skill("unarmed", 70);
    set_skill("spear", 70);
    set("force", 500);
    set("force_factor", 40);
    set_skill("dodge", 70);
    set_skill("parry", 70);
    setup();

    carry_object("/d/obj/cloth/bingfu")->wear();
    carry_object("/d/obj/weapon/spear/tieqiang")->wield();

}
void init()
{
    add_action("do_answer", "answer");
}

int do_answer(string arg)
{
    string *ans = ({"����","������","����","�Ӿ�"});

    if (this_player()->query_temp("aolai_drill") != "want") return 0;
    if (!arg) return notify_fail("��˵ʲô��\n");
    if (arg == "0" || arg == "1" || arg == "2" || arg == "3")
        arg = ans[atoi(arg)];
    message_vision("$N�����" + arg + "��\n", this_player());
    if (arg == "������") {
        command("consider");
        command("say �����ֿ��ԣ�����׼��������������ѵ����\n");
        this_player()->set_temp("aolai_drill", "allow");
    }
    else
        command("say ���˵ʲô���������ң�\n");
    return 1;
}

void unconcious()
{
    object ob;
    object me = this_object();
    object where = environment (me);

    message_vision ("\n$N���������ð�����ҵ������ף���������ô��ʰ�㣡��˵�յ���ײײ��ǿ�������䳡��\n",me);
    message_vision ("\n��һ��$N���˹�����\n",me);
    ob = new(__FILE__);
    ob->move(where);
    destruct(me);
}

void die()
{
    unconcious();
}
