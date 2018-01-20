#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG

��Ƿ������ͷ�������ٿ���ȴ�����˼�ס��һ�㣬��������ڡ������ǣ�

������޺���������Ƹ��񣬹�ҡƬƬ��ϼ���鴰���ң����ʰ����������
���������йң��ӻ��������⡣�ּ���һ�����������������÷������
���������ɳ����꣬��Ȼ����˼ҡ�

���ն�ʱ���������м䣬���ҹۿ���ֻ����������һʯ��(shi jie)��
LONG
    );

    set("item_desc", ([
        "shi jie": @SHIJ
��������������������������������
��������������ˮ������������������������
������������������������������������������
����������������������������ɽ����������
����������������������������������������
����������������������������ء���������
��������������������������������
SHIJ
    ]));

    set("exits", ([
        "east"   : __DIR__"shifang",
    ]));
    create_door("east", "ʯ��", "west", DOOR_CLOSED);
    setup();
}

void init ()
{
    add_action("do_jump", "jump");
}

int do_jump(string arg)
{
    object me = this_player();
    if (!arg || (arg != "bridge" && arg != "qiao"))
        return notify_fail("�����Ķ�����\n");

    if (random(30) + me->query("kar") < 30) {
        message_vision("$N��������һԾ���ִӰ����ˤ��������\n", me);
        me->unconcious();
    } else {
        message_vision("$N�����Ϸ����ݳ��ٲ���\n", me);
        me->move(__DIR__"fall");
    }

    return 1;
}
