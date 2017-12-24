// ALi by NewX

#include <ansi.h>

inherit NPC;

string *prisoner_descs = ({
    "һ��������Ů�ӣ�������Щ���죬�ƺ���ĳһ���������е�������Ů����\n",
    "һ�����εεĴ���һ�����Ǹ���С�㡣\n",
    "һ�������Ů������Ȼ���¹����ӣ�������ʱ�书����ȫ�����⣬���˶������ڵ��̼����ϡ�\n",
    "һ�����˴�Ĺ�Ĺ���ӣ����ڵ��̼����ϣ�ɪɪ������\n",
});

string *status_descs = ({
    "��ʱ�����·������˸����⣬�����˺����ۣ��Ǳ�������",
    "��ʱ����������־���Ϣ����������˶�������Ҳ�޾���ɵġ�",
    "��ʱ�ܵ���Χ������Ӱ�죬��ȻҲ������ֹ�Ĳ����š�",
});

void create()
{
    set_name("����", ({"fan", "girl"}));
    set("title", CYN "������ס��" NOR);
    set("long", prisoner_descs[random(sizeof(prisoner_descs))]);
    set("looking", status_descs[random(sizeof(status_descs))]);

    set("gender", "Ů��");
    set("age", 15+random(20));
    set("per", 20+random(15));
    set("combat_exp", 10000);
    set_skill("dodge", 10);
    set_skill("moondance", 20);
    set("max_gin", 200);
    set("max_atman", 200);
    
    set("no_get", "�������������εĹ̶��ţ������ⲻ������\n");
    set_temp("no_move", 1);

    setup();
}

int accept_fight(object me)
{
    command("fear " + me->query("id"));
    command("say " + RANK_D->query_respect(me)
        + "������ū�����ܸ������֣�\n");
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
