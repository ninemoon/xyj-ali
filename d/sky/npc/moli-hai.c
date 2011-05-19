inherit NPC;

void create()
{
    set_name("ħ��", ({ "moli hai", "duowen tianwang", "hai", "tianwang" }));
    set("gender", "����");
    set("long",
        "ħ���Ľ�֮һ��ʹһ��������������һ�����ã����������ң�Ҳ��\n"
        "�ء�ˮ���𡢷磬������������������������ƽ�һ�㡣\n"
    );
    set("age", 50);
    set("title", "��������");
    set("attitude", "heroism");
    set("str", 40);
    set("int", 30);
    set("max_kee", 1100);
    set("kee", 1100);
    set("max_sen", 1100);
    set("sen", 1100);
    set("combat_exp", 2500000);
    set("force", 2500);
    set("max_force", 1500);
    set("mana", 2500);
    set("max_mana", 1600);
    set("force_factor", 80);
    set("mana_factor", 80);
    
    set("nkgain", 800);

    set_skill("unarmed", 150);
    set_skill("raptor-talon", 150);
    set_skill("parry", 150);
    set_skill("dodge", 150);
    set_skill("stick", 150);
    set_skill("keening-stick", 150);
    set_skill("force", 150);
    set_skill("spells", 150);
    set_skill("moshenbu", 150);
    map_skill("dodge", "moshenbu");
    map_skill("parry", "keening-stick");
    map_skill("spear", "keening-stick");
    map_skill("unarmed", "raptor-talon");
    set("inquiry", ([
        "name" : "���¶�������ħ�񺣣���ʥ�Ͱ��������š�",
        "here" : "�������������, ���ھ�������ˡ�",
    ]));

    setup();
    carry_object("/d/sea/obj/dragonstick")->wield();
    carry_object("/d/obj/armor/jinjia")->wear();
}

void kill_ob (object ob)
{
    object me = this_object();
    set("combat_exp", 3000000+random(1330000));
    set("eff_kee", 1100);
    set("kee", 1100);
    set("sen", 1100);
    set("eff_sen", 1100);
    message_vision ("$N˵�������������죡\n",me);
    ::kill_ob(ob);
}