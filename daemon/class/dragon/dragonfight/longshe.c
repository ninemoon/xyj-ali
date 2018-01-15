//龙蛇合击

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

//int valid_enable(string usage) { return usage=="array"; }

//int form_array(object leader)
int perform(object leader, object target)
{
        object *member,ob, weapon;
        int i,j,n;
        int max,min,skill;

        member = leader->query_team();
        if( sizeof(member) != 2 )
                return notify_fail("一条龙怎么戏？\n");

        j=sizeof (member);
        for (i=0;i<j;i++)
        {
                ob=member[i];
                if (!ob||!living(ob)||!ob->is_character())
                {
                        return notify_fail("你想和谁一齐使用双龙戏珠？\n");
                }
                if (ob->query_temp("array/name"))
                {
                        return notify_fail("双龙合体了。\n");
                }
                if (environment(leader)!=environment(ob))
                {
                        return notify_fail("人数不够两人。\n");
                }
                if (!ob->query_skill("dragonfight",1))
                {
                        return notify_fail(ob->name()+"还不会龙形搏击呢！\n");
                }
                if (ob->is_ghost())
                {
                        return notify_fail("只有阳间的人才能再现双龙合体。\n");
                }

                if( (int)ob->query("max_force") < 50 )
                        return notify_fail(ob->query("name")+"的内力不够。\n");

                if( (string)ob->query_skill_mapped("force")!= "dragonforce")
                        return notify_fail(ob->query("name")+"没有使用龙神心法。\n");

                if( !(weapon = ob->query_temp("weapon")))
                        return notify_fail(ob->query("name")+"必须空手。\n");

                if( (int)ob->query_skill("dragonfight",1)<30)
                        return notify_fail(ob->query("name")+"的龙形搏击还不够熟练。\n");

                if( (string)ob->query_skill_mapped("unarmed")!="dragonfight")
                        return notify_fail(ob->query("name")+"必须使用龙形搏击。\n");
        }

//get the average array skill of the team
        n=0;
        for (i=0;i<j;i++)
        {
                ob=member[i];
                n+=(int)ob->query_skill("dragonfight",1);
        }
        n/=2;

//get the difference of the array skill,
//first get the max and mix skill level of the array
        max=member[0]->query_skill("dragonfight",1);
        min=max;
        for (i=0;i<j;i++)
        {
                skill=member[i]->query_skill("dragonfight",1);
                if(skill>max)
                        max=skill;
                else if(skill<min)
                        min=skill;
        }

//and the leader is important
        n += leader->query_skill("dragonfight", 1) * 5;
        n /= max - min + 1;
        for (i=0;i<j;i++)
        {
                ob=member[i];
                ob->set_temp("no_quit",1);

                ob->set_temp("array/name","dragonfight");
                ob->set_temp("array/level",n);

                ob->add_temp("apply/attack",n);
                ob->add_temp("apply/defense", n);
                ob->add_temp("apply/damage",n);
                ob->add_temp("apply/armor", n);
        }
        message_vision( HIG "$N与$N两条飞龙遥飞九天，双龙合体了！\n" NOR, leader);
        return 1;
}

int dismiss_array(object person)
{
        int i,j,n;
        object *member,ob;

        member=person->query_team();
        j=sizeof(member);
        n=person->query_temp("array/level");
        for (i=0;i<j;i++)
        {
                ob=member[i];
                ob->delete_temp("array");
                ob->add_temp("apply/attack",-n);
                ob->add_temp("apply/damage",-n);
                ob->add_temp("apply/defense",-n);
                ob->add_temp("apply/armor", -n);
                tell_object(ob,"双龙离位！\n");
        }
}

//if the leader kills enemy, then all members in the array kill enemy
int array_kill(object leader, object enemy)
{
        object *member, ob;
        int i,j;
        member=leader->query_team();
        j=sizeof(member);

        for(i=0;i<j;i++) {
                ob=member[i];
                ob->kill_ob(enemy);
        }

        return 1;
}

