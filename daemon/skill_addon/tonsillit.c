// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
//remove shaqi require.2/15
/*
        if( (int)me->query("bellicosity") < (int)me->query_skill("tonsillit") * 40 )
                return notify_fail("���ɱ���������޷�������������������\n");
*/
   if( (int)me->query_skill("tonsillit", 1) >= 250 )
     return notify_fail("����������ޣ����������������˼��ޡ�\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧϰ��Ӧ������ߣ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("ghost") + "/tonsillitis/" + func;
}
