// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/33tian/doushuai-gate
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�߽�������ԭ�����������ʮ�ֺ�ΰ�������Ϻ��һ����(bian)��
������һ������ (duilian)�����澲���ĵģ�Ҳ��֪��û���ˡ�����
��������ԼԼ���Կ���һƬ���֣�����Ǹ����޵ĺõط���
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"west1",
]));
  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bian" : "�����ʹ���
",
]));

  setup();
}