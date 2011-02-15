// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
   if( me->is_fighting() )   return notify_fail("������ս���У�\n");
   
   if( (int)me->query("mana") < 20 ) return notify_fail("��ķ��������ˣ�\n");

   if( !arg ) return notify_fail("��Ҫ�����ŷ���д˭�����֣�\n");

   sheet->set_name(YEL "����׷���" NOR, ({ "haunting sheet", "sheet"}) );   
   sheet->set("attach_func", (: call_other, __FILE__, "do_haunt", arg :) );
   me->add("mana", -20);
   me->receive_damage("sen", 10);

   return 1;
}

int do_haunt(string target, object who)
{
   object dest;

   if( !who->is_zombie() )
     return notify_fail(YEL "����׷���" NOR "ֻ�����ڽ������ϡ�\n");

   if( !who->query("possessed") )
     return notify_fail("��������÷�����ס" + who->name() + "����ʹ���������\n");

   dest = present(target, environment(who));
   if( !dest ) dest = find_player(target);
   if( !dest ) dest = find_living(target);
   if( objectp(dest) ) {
     who->kill_ob(dest);
     who->set_leader(dest);
     message_vision("$N�۾���Ȼ�������૵�˵����" RED "ɱ....��....$n....\n" NOR,
        who, dest);
     if( environment(dest)==environment(who) ) {
        dest->fight_ob(who);
     }
   } else {
     message_vision("$N�۾���Ȼ�������૵�˵����" RED "ɱ....ɱ....ɱ....\n" NOR,
        who);
     if( this_player() ) {
        who->kill_ob(this_player());
        who->set_leader(this_player());
        this_player()->fight_ob(who);
     }
   }
   return 1;
}