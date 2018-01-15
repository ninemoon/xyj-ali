
// expell.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    object ob;
    string *skname, myfamily;
    mapping skills;
    int i;
    if (!arg || !ob = present(arg, environment(me)))
        return notify_fail("你要将谁逐出师门？\n");

    if (!ob->is_character())
        return notify_fail("你要开革「谁」？\n");

    if (!userp(ob))
        return notify_fail("你只能开革玩家所扮演的人物。\n");

    if (me->query("family/privs")==-1
    &&  (string)me->query("family/family_name")==(string)ob->query("family/family_name")) {
        message_vision("$N对着$n说道：从今天起，你再也不是我"
            + me->query("family/family_name") + "的弟子了，你走吧！\n\n",
            me, ob);
        tell_object(ob, "\n你被" + me->query("family/title") + "开革出师门了！\n\n");
    } else if (ob->is_apprentice_of(me)) {
        message_vision("$N对着$n说道：从今天起，你我师徒恩断情绝，你走吧！\n", me, ob);
        message_vision("$N对着$n说道：江湖风波，善恶无形，好自为之。。。\n\n", me, ob);
        tell_object(ob, "\n你被师父开革出师门了！\n\n");
    } else
        return notify_fail("这个人不是你的弟子。\n");

    me->expell_apprentice(ob);
    ob->save();
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : expell <某人>

这个指令可以让你开除不成才的弟子，如果你是掌门人，被开除的弟子将彻底
离开门派；否则他虽离开你的门下，但仍属于这个门派，可以随便传投本派其
他师父。

HELP
    );
    return 1;
}
