// ALI by NewX

// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string *sex_ranking_male = ({"��������", "��������", "��Ů����"});
string *sex_ranking_female = ({"��������", "���ڸ���", "��������"});

string display_attr(int gift, int value);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
    object ob;
    mapping my;
    string line, str;

    seteuid(getuid(me));

    if (!arg)
        ob = me;
    else if (wizardp(me)) {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
    } else
        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

    my = ob->query_entire_dbase();

    write(NOR YEL"\n�ԡԡԡԡԡԡԡԡԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡԡԡԡԡԡԡԡԡ�\n"NOR);
    line = sprintf(BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1));

    if (my["always_young"])
        line += sprintf(" �Ա�"HIG"%-4s"NOR"  ���䣺"HIY"%-4s��"NOR"  ��Ԫ��"CYN"%-6s��"NOR" \n\n",
            my["gender"], chinese_number(my["fake_age"]), chinese_number(my["age"]));
    else
        line += sprintf(" �Ա�"HIG"%-4s"NOR"  ���䣺"HIY"%-4s��"NOR" \n\n",
            my["gender"], chinese_number(my["age"]));

    line += sprintf(
            " ������[%s]  | ������[%s]  | ��ʶ��[%s]  | ��ò��[%s]\n",
            display_attr(my["str"], ob->query_str()),
            display_attr(my["cps"], ob->query_cps()),
            display_attr(my["cor"], ob->query_cor()),
            display_attr(my["per"], ob->query_per()),
            );
    line += sprintf(
            " ���ԣ�[%s]  | ���ԣ�[%s]  | ���ǣ�[%s]  | ��Ե��[%s]\n\n",
            display_attr(my["int"], ob->query_int()),
            display_attr(my["spi"], ob->query_spi()),
            display_attr(my["con"], ob->query_con()),
            display_attr(my["kar"], ob->query_kar()),
            );

    if (mapp(my["family"]))
        line += sprintf(" ��  �ɣ�" HIC "%-6s" NOR, my["family"]["family_name"]);
    else
        line += sprintf(" ��  �ɣ�" HIC "��" NOR);
    if (mapp(my["family"]) && my["family"]["master_name"])
        line += sprintf("  ʦ  ����" YEL "%s" NOR, my["family"]["master_name"]);
    else
        line += sprintf("  ʦ  ����" YEL "��" NOR);
    if (stringp(my["secret_master_name"]))
        line += sprintf("  ����ʦ����" MAG "%s\n" NOR, my["secret_master_name"]);
    else
        line += "\n";

    line += sprintf(" ս  ����ɱ %d �ˣ�����NPC %d �ˣ�������� %d ��\n",
        my["MKS"] + my["PKS"], my["MKS"], my["PKS"]);

    line += " �Ծ��飺";
    if (mapp(my["sex"]) && mapp(my["sex"]["lovers"])) {
        if (my["gender"] == "����") {
            line += HIY + sex_ranking_male[sizeof(my["sex"]["lovers"])/10] + NOR;
            if (!my["sex"]["first_semen_lost"])
                line += "�����Ա���" HIB "ͯ��֮��" NOR;
        } else if (my["gender"] == "Ů��") {
            line += HIY + sex_ranking_female[sizeof(my["sex"]["lovers"])/10] + NOR;
            if (!my["sex"]["hymen_broken"])
            line += "�����Ա���" HIB "����֮��" NOR;
        }
    }
    else
        line += HIB + (my["gender"]=="����"?"ͯ":"��") + "��֮��" NOR;
    
    if (undefinedp(my["sex_leaning"]))
        line += "\n";
    else if (my["sex_leaning"] == "both")
        line += " ������" HIY "����" NOR "��" HIY "Ů��" NOR "\n";
    else if (my["sex_leaning"]=="same") {
        if (my["gender"]=="Ů��")
            line += " ������" HIY "Ů��" NOR "\n";
        else
            line += " ������" HIY "����" NOR "\n";
    } else if (my["sex_leaning"]=="diff") {
        if (my["gender"]=="Ů��")
            line += " ������" HIY "����" NOR "\n";
        else
            line += " ������" HIY "Ů��" NOR "\n";
    } else
        line += "\n";

    if (ob->query("balance"))
        line += " ��  �" + MONEY_D->money_str((int)ob->query("balance"))+"���\n\n";
    else
        line += " ��  �" HIW "û���κδ��" NOR "\n\n";

    line += RED " ����ȡ��" NOR "��" + OBSTACLES_D->check_obstacles_short(ob) + "\n";
    line += RED " �����칬" NOR "��" + OBSTACLES_D->check_obstacles_short(ob, "dntg") + "\n\n";

    {
        /* ap/dp calc */
        string skill_type;
        object weapon;
        int attack_points, dodge_points, parry_points;

        if (objectp(weapon = ob->query_temp("weapon")))
            skill_type = weapon->query("skill_type");
        else
            skill_type = "unarmed";

        attack_points = COMBAT_D->skill_power(ob, skill_type,
            SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, skill_type,
            SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge",
            SKILL_USAGE_DEFENSE);
    
        line += sprintf(" �������ۣ�%s%-10d%s(%s%+5d%s)  �������ۣ�%s%-10d%s(%s%+5d%s)\n",
            HIW, attack_points/100 + 1, NOR,
            HIR, ob->query_temp("apply/damage"), NOR,
            HIW, (dodge_points + (weapon? parry_points:(parry_points/10)))/100 + 1, NOR,
            HIY, ob->query_temp("apply/armor"), NOR);
    }

    line += sprintf(" ���о��磺%s           ��ѧ���磺%s\n",
                RANK_D->describe_exp(ob->query("combat_exp")),
                RANK_D->describe_skills(ob->query_skills()));
    line += sprintf(" ������Ϊ��%s           ������Ϊ��%s\n",
                RANK_D->describe_mana(ob->query("max_mana")),
                RANK_D->describe_force(ob->query("max_force")));

    line += sprintf("\n %s�� ["YEL"���μ�"NOR"��"HIG"��������"NOR"] ���Ѿ����� %s ������ \n",
        ob == me ? "��" : ob->name(1),
        HIR + FINGER_D->age_string( (int)ob->query("mud_age")) + NOR);
    line += NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR;

    write(line);
    return 1;
}

string display_attr(int gift, int value)
{
    if (value > gift) return sprintf( HIY "%3d" NOR, value );
    else if (value < gift) return sprintf( CYN "%3d" NOR, value );
    else return sprintf("%3d", value);
}

int help(object me)
{
    write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ���ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��

see also : hp
HELP
    );
    return 1;
}

