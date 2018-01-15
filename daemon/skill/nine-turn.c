// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// nine-turn.c
inherit FORCE;

string name() { return "九转玄功"; }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
    string mark;
    if (!stringp(mark = me->query("mark/nine-turn"))) {
        if (random(me->query_kar()) > 20)
            mark = "true";
        else
            mark = "false";
        me->set("mark/nine-turn", mark);
    }
    if (mark == "true") return 1;
    else return notify_fail("修习九转玄功须有缘分，你与此术无缘，还是算了吧。\n");
}

string exert_function_file(string func)
{
    return CLASS_D("puti") + "/nine-turn/" + func;
}

