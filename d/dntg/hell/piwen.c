
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("����", ({"pi wen","piwen","wen"}));
    set_weight(10);
    set("unit", "��");
    setup();
}

void init()
{
    object wc, me = this_player();
    if (userp(environment()))
        call_out("wc_lootme", 1, me);
    add_action("do_look","look");
}

void wc_lootme(object me)
{
    object wc;

    if (environment() != me) return;

    if (wc = query("bai") || wc = query("hei")) {
        if (environment(me) == environment(wc))
            message_vision("$Nһ�ѽ�$n���е����Ķ��˻�ȥ��������˾�������������\n", wc, me);
        else
            message_vision("$N����ææ�ܹ�����һ�ѽ�$n���е����Ķ��˻�ȥ��������˾�������������\n", wc, me);
        move(wc);
    }
}

int do_look(string arg)
{
    object me = this_player();
    object helper = me->query_temp("dntg_helper");

    if (!arg || !id(arg)) return 0;
    if (!helper) return 0;
    write(this_object()->long());
    if (query("target") != me->query("name")) return 1;
    me->set_temp("dntg_hell/next", query("wang"));
    message_vision(HIR "$N�������ģ���Ȼ��ŭ��������˺�˸����飬��У�������ȥ���������������\n" NOR, me);
    __DIR__"trouble"->install(me, helper->get_palace_rooms());
    destruct(this_object());
    return 1;
}

void setup_piwen(object me, object bai, object hei)
{
    mapping wangs = ([ "qingguang":"�ع���", "songdi":"�ε���", "chujiang":"������",
        "chuguan":"������", "pingdeng":"ƽ����", "dushi":"������", "taishan":"̩ɽ��",
        "lunzhuan":"��ת��", "biancheng":"�����", "yanluo":"������" ]);
    string wang;

    wang = keys(wangs)[random(sizeof(wangs))];
    set("long","    ��" + me->query("name")
                + "�����Ѿ�������ڰ��޳�������ǹ��ù鰸��\n\n"
                + "                            "+wangs[wang]+"  ��\n\n\n");
    set("target", me->query("name"));
    set("wang", wang);

    bai->set("inquiry/����", (: call_other, __FILE__, "assail", this_object() :));
    bai->set("inquiry/ԩ��", (: call_other, __FILE__, "assail", this_object() :));
    bai->set("inquiry/ԩ��", (: call_other, __FILE__, "assail", this_object() :));
    hei->set("inquiry/����", (: call_other, __FILE__, "assail", this_object() :));
    hei->set("inquiry/ԩ��", (: call_other, __FILE__, "assail", this_object() :));
    hei->set("inquiry/ԩ��", (: call_other, __FILE__, "assail", this_object() :));
    set("bai", bai);
    set("hei", hei);
    if (random(2)) move(hei);
    else move(bai);
}

string assail(object ob, object wc)
{
    object me = this_player();
    if (!ob || !me) return 0;
    
    if (me->query("name") != ob->query("target")) return 0;

    ob->move(wc);
    return "�Ұ��������鹴�ˣ�����ԩ�������뷢�˹���֮ڤ������(complain)��";
}
