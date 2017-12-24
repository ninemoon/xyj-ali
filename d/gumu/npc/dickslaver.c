// ALi by NewX

#include <ansi.h>

inherit NPC;

string *slaver_descs = ({
    "һ����ϸ���������꣬�������㣬üĿ�д�����ɬ����Ϣ����ͬһֻ�ܾ���С¹��\n",
    "һ���ߴ�׳�����У��������⣬����뺷��\n",
    "һ�����޸���֮��������������֮����Ҳ���������ᡣ\n���������µ�������ʵ��С����ʹ�������Ѿ�����ͨ�˴�ܶ��ˡ�\n",
    "һ��ϸƤ���������ˣ���Ȼ�Ǹ������ӣ��ƺ����򻹲�������������Ӧ��Ҳ�Ǹ����֡�\n��ϧ����������ħ�ĳ�Ѩ���书������û�á�\n",
});

string *status_descs = ({
    "��ʱ���µ����ޣ�����ŭͦ�����������Ե����ơ�",
    "��ʱ����������־���Ϣ����������˶�������Ҳ�޾���ɵġ�",
    "��ʱ�ܵ���Χ������Ӱ�죬��ȻҲ������ֹ�ĸ߸߲���",
});

void create()
{
    set_name("��ū", ({"slaver", "boy"}));
    set("title", CYN "������ס��" NOR);
    set("long", slaver_descs[random(sizeof(slaver_descs))]);
    set("looking", status_descs[random(sizeof(status_descs))]);

    set("gender", "����");
    set("age", 15+random(20));
    set("per", 20+random(15));
    set("combat_exp", 10000);
    set_skill("dodge", 10);
    set_skill("moondance", 20);
    set("max_gin", 200);
    set("max_atman", 200);
    
    set("no_get", "��ū���������εĹ̶��ţ������ⲻ������\n");
    set_temp("no_move", 1);

    setup();
}

int accept_fight(object me)
{
    command("fear " + me->query("id"));
    command("say " + RANK_D->query_respect(me)
        + "������С�����ܸ������֣�\n");
    return 0;
}

mixed set_temp(string prop, mixed data)
{
    if (prop == "no_move") return ::set_temp("no_move", 1);
    else return ::set_temp(prop, data);
}

int delete_temp(string prop)
{
    if (prop == "no_move") return ::set_temp("no_move", 1);
    else return ::delete_temp(prop);
}
