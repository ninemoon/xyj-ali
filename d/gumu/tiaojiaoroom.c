// ALi by NewX

inherit ROOM;

void create ()
{
    set("short", "��������");
    set("long", @LONG

�������������������Ʈ��һ�����ŵ���ζ��
������������Ĺ�ɵ��˵ĵط���Ҳ�ǹ�Ĺ���ӿ��������ⷢй������
�ط�����Ȼ������ֻ��Ů��²��������ֻ����˫ͷ�����á�

LONG);

    set("objects", ([ /* sizeof() == 3 */
        __DIR__"npc/prisoner" : 3,
        __DIR__"npc/execgirl" : 1,
    ]));

    set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"shidong3",
    ]));

    setup();
}

