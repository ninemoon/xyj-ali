// room

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "���չ�");
    set("long", @LONG

���������רΪ��ʮ������ġ���ʮ��λ�ǹ���Ϊ����շ⣬ʵ
����������ɽ�󴨣�����ĺ���ƽʱ��������۽��ƣ�ֻ����͢
�����ش�����������������졣��ʮ���޵������������ʱ����
������֮����

LONG);

    set("exits", ([ /* sizeof() == 3 */
        "west"     : __DIR__"kangjingong",
        "northwest" : __DIR__"jiaomugong",
        "southwest"      : __DIR__"ditugong",
    ]));
    set("objects", ([
        __DIR__"stars/vovo" : 1,
    ]));
    setup();
}
