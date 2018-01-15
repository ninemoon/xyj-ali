// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
    // need this default, otherwise looks too ugly sometimes.
    if (strlen(ob->query("added_title"))<1)
        ob->set("added_title", "某某");

    if (ob->is_ghost()) return HIB "【 鬼  魂 】" NOR;
    if (wizardp(ob)) return HIW "【 巫  师 】" NOR;

    switch (ob->query("gender"))
    {
// begin 女性：
        case "女性":
            switch (ob->query("class"))
            {
//------------------rank for girls--------------------
case "xian":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "【 女仙童 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "【 小仙女 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "【 仙  女 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "【"+ob->query("added_title")+"仙子】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return GRN "【"+ob->query("added_title")+"圣女】" NOR;
    else
        return GRN "【"+ob->query("added_title")+"女神】" NOR;
    break;
case "taoist":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "【 女道童 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "【 女道士 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "【 玄  女 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "【"+ob->query("added_title")+"玄女】" NOR;
    else
        return GRN "【"+ob->query("added_title")+"天女】" NOR;
    break;
case "bonze":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "【 小尼姑 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "【 尼  姑 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "【 比丘尼 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "【"+ob->query("added_title")+"神尼】" NOR;
    else
        return GRN "【"+ob->query("added_title")+"菩萨】" NOR;
    break;
case "dragon":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "【 小宫娥 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "【 宫  女 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "【 小龙女 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "【"+ob->query("added_title")+"龙女】" NOR;
    else
        return GRN "【"+ob->query("added_title")+"公主】" NOR;
    break;
case "ghost":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "【 小  鬼 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "【 女  鬼 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "【 女判官 】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return GRN "【"+ob->query("added_title")+"天鬼】" NOR;
    else
        return GRN "【"+ob->query("added_title")+"女王】" NOR;
    break;
case "yaomo":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "【 小妖女 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "【 妖  女 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "【 妖  精 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "【"+ob->query("added_title")+"公主】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return GRN "【"+ob->query("added_title")+"魔女】" NOR;
    else
        return GRN "【"+ob->query("added_title")+"女王】" NOR;
    break;
case "fighter":
    if ((int)ob->query("combat_exp")<1000)
        return GRN "【 女  兵 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return GRN "【 女校尉 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return GRN "【 女将军 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return GRN "【"+ob->query("added_title")+"将军】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return GRN "【"+ob->query("added_title")+"大将军】" NOR;
    else
        return GRN "【"+ob->query("added_title")+"大元帅】" NOR;
    break;
case "scholar":
    if ((string)ob->query("added_title")=="某某") {
        if ((int)ob->query_skill("literate", 1)<20)
            return GRN "【 女学童 】" NOR;
        else if ((int)ob->query_skill("literate", 1)<100)
            return GRN "【 才  女 】" NOR;
        else
            return GRN "【 女学士 】" NOR;
    } else {
     if ((int)ob->query_skill("literate", 1)<20)
         return GRN "【 女学童 】" NOR;
     else if ((int)ob->query_skill("literate", 1)<100)
         return GRN "【"+ob->query("added_title")+"秀才】" NOR;
     else
         return GRN "【"+ob->query("added_title")+"学士】" NOR;
    }
    break;
case "dancer":
    return GRN "【 舞  妓 】" NOR;
    break;
default:
    return MAG "【 平  民 】" NOR;
//------------------end rank for girls--------------------
            }
// begin 男性：
        default:
        switch (ob->query("class"))
        {
//------------------rank for men--------------------
case "xian":
    if ((int)ob->query("combat_exp")<1000)
        return RED "【 仙  童 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "【 散  仙 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "【 大  仙 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "【"+ob->query("added_title")+"大仙】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "【"+ob->query("added_title")+"大仙】" NOR;
    else
        return RED "【"+ob->query("added_title")+"天尊】" NOR;
    break;
case "taoist":
    if ((int)ob->query("combat_exp")<1000)
        return RED "【 道  童 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "【 道  士 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "【 道  长 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "【"+ob->query("added_title")+"天师】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "【"+ob->query("added_title")+"真人】" NOR;
    else
        return RED "【"+ob->query("added_title")+"天尊】" NOR;
    break;
case "bonze":
    if ((int)ob->query("combat_exp")<1000)
        return RED "【 小沙弥 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "【 和  尚 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "【 圣  僧 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "【"+ob->query("added_title")+"尊者】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "【"+ob->query("added_title")+"罗汉】" NOR;
    else
        return RED "【"+ob->query("added_title")+"菩萨】" NOR;
    break;
case "dragon":
    if ((int)ob->query("combat_exp")<1000)
        return RED "【 虾  兵 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "【 蟹  将 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "【巡海夜叉】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "【"+ob->query("added_title")+"蛟龙】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "【"+ob->query("added_title")+"龙】" NOR;
    else
        return RED "【"+ob->query("added_title")+"龙王】" NOR;
    break;
case "ghost":
    if ((int)ob->query("combat_exp")<1000)
        return RED "【 小  鬼 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "【   鬼   】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "【 判  官 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "【"+ob->query("added_title")+"无常】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "【"+ob->query("added_title")+"鬼王】" NOR;
    else
        return RED "【"+ob->query("added_title")+"王】" NOR;
    break;
case "yaomo":
    if ((int)ob->query("combat_exp")<1000)
        return RED "【 小  妖 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "【 妖  怪 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "【 妖  仙 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "【 "+ob->query("added_title")+"老魔 】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "【"+ob->query("added_title")+"魔王】" NOR;
    else
        return RED "【"+ob->query("added_title")+"大圣】" NOR;
    break;
case "fighter":
    if ((int)ob->query("combat_exp")<1000)
        return RED "【 小  兵 】" NOR;
    else if ((int)ob->query("combat_exp")<10000)
        return RED "【 小  校 】" NOR;
    else if ((int)ob->query("combat_exp")<100000)
        return RED "【 参  将 】" NOR;
    else if ((int)ob->query("combat_exp")<500000)
        return RED "【"+ob->query("added_title")+"将军】" NOR;
    else if ((int)ob->query("combat_exp")<1000000)
        return RED "【"+ob->query("added_title")+"大将军】" NOR;
    else
        return RED "【"+ob->query("added_title")+"大元帅】" NOR;
    break;
case "scholar":
    if ((string)ob->query("added_title")=="某某") {
        if ((int)ob->query_skill("literate", 1)<20)
            return RED "【 童  生 】" NOR;
        else if ((int)ob->query_skill("literate", 1)<100)
            return RED "【 秀  才 】" NOR;
        else
            return RED "【 大学士 】" NOR;
    } else {
        if ((int)ob->query_skill("literate", 1)<20)
            return RED "【 童  生 】" NOR;
        else if ((int)ob->query_skill("literate", 1)<100)
            return RED "【"+ob->query("added_title")+"秀才】" NOR;
        else
            return RED "【"+ob->query("added_title")+"学士】" NOR;
    }
    break;
default:
    return "【 平  民 】";
//------------------end rank for men--------------------
        }
    }
}

int query_age(object ob)
{
    if (ob->query("always_young")
    &&  (int)ob->query("fake_age") < (int)ob->query("age"))
        return (int)ob->query("fake_age");
    else
        return (int)ob->query("age");
}

string query_respect(object ob)
{
    int age;
    string str;

    if (stringp(str = ob->query("rank_info/respect")))
        return str;

    age = query_age(ob);
    switch (ob->query("gender"))
    {
        case "女性":
        switch (ob->query("class"))
        {
case "bonze":
    if (age < 18) return "小师太";
    else return "师太";
    break;
case "taoist":
    if (age < 18) return "小仙女";
    else return "仙子";
    break;
case "xian":
    if (age < 18) return "小仙女";
    else return "仙子";
    break;
default:
    if (age < 18) return "小姑娘";
    else if (age < 50) return "姑娘";
    else return "婆婆";
    break;
        }
        case "男性":
        default:
        switch (ob->query("class"))
        {
case "xian":
    if (age < 18) return "小神仙";
    else if (age < 50) return "仙兄";
    else return "老神仙";
    break;
case "bonze":
    if (age < 18) return "小师父";
    else if (age < 50) return "大师";
    else return "长老";
    break;
case "taoist":
    if (age < 18) return "小道爷";
    else if (age < 50) return "道兄";
    else return "道长";
    break;
case "fighter":
    if (age < 18) return "小将军";
    else if (age < 50) return "大将军";
    else return "老将军";
    break;
case "scholar":
    if (age < 18) return "小相公";
    else if (age < 50) return "相公";
    else return "老先生";
    break;
/*
case "swordsman":
    if (age < 18) return "小老弟";
    else if (age < 50) return "壮士";
    else return "老前辈";
    break;
*/
default:
    if (age < 18) return "小兄弟";
    else if (age < 50) return "壮士";
    else return "老爷子";
    break;
        }
    }
}

string query_rude(object ob)
{
    int age;
    string str;

    if (stringp(str = ob->query("rank_info/rude")))
        return str;

    age = query_age(ob);
    switch (ob->query("gender"))
    {
        case "女性":
        switch (ob->query("class"))
        {
case "xian":
    if (age < 30) return "小妖精";
    else if (age < 50) return "妖女";
    else return "老妖婆";
    break;
case "yaomo":
    if (age < 30) return "小妖女";
    else if (age < 50) return "妖女";
    else return "老妖婆";
    break;
case "bonze":
    if (age < 30) return "小贼尼";
    else if (age < 50) return "贼尼";
    else return "老贼尼";
    break;
case "taoist":
    if (age < 30) return "小妖女";
    else if (age < 50) return "妖女";
    else return "老妖婆";
    break;
default:
    if (age < 30) return "小贱人";
    else if (age < 50) return "贱人";
    else return "死老太婆";
    break;
        }
        case "男性":
        default:
        switch (ob->query("class"))
        {
case "xian":
    if (age < 50) return "死妖怪";
    else return "老妖怪";
    break;
case "yaomo":
    if (age < 50) return "死妖怪";
    else return "老妖怪";
    break;
case "bonze":
    if (age < 50) return "死秃驴";
    else return "老秃驴";
    break;
case "taoist":
    return "死牛鼻子";
    break;
case "scholar":
    if (age < 18) return "小书呆子";
    else if (age < 50) return "臭书呆子";
    else return "老童生";
    break;
default:
    if (age < 18) return "小王八蛋";
    else if (age < 50) return "臭贼";
    else return "老匹夫";
    break;
        }
    }
}

string query_self(object ob)
{
    int age;
    string str;

    if (stringp(str = ob->query("rank_info/self")))
        return str;

    age = query_age(ob);
    switch (ob->query("gender"))
    {
        case "女性":
        switch (ob->query("class"))
        {
case "bonze":
    if (age < 50) return "贫尼";
    else return "老尼";
    break;
case "taoist":
    return "贫道";
    break;
default:
    if (age < 30) return "小女子";
    else return "妾身";
    break;
        }
        case "男性":
        default:
        switch (ob->query("class"))
        {
case "bonze":
    if (age < 50) return "贫僧";
    else return "老纳";
    break;
case "taoist":
    return "贫道";
    break;
case "scholar":
    if (age < 30) return "晚生";
    else return "不才";
    break;
default:
    if (age < 50) return "在下";
    else return "老头子";
    break;
        }
    }
}

string query_self_rude(object ob)
{
    int age;
    string str;

    if (stringp(str = ob->query("rank_info/self_rude")))
        return str;

    age = query_age(ob);
    switch (ob->query("gender"))
    {
        case "女性":
        switch (ob->query("class"))
        {
case "bonze":
    if (age < 50) return "贫尼";
    else return "老尼";
    break;
default:
    if (age < 50) return "本姑娘";
    else return "老娘";
    break;
        }
        case "男性":
        default:
        switch (ob->query("class"))
        {
case "bonze":
    if (age < 50) return "大和尚我";
    else return "老和尚我";
    break;
case "taoist":
    return "道爷我";
    break;
case "scholar":
    if (age < 50) return "本相公";
    else return "老夫子我";
    break;
default:
    if (age < 18) return "你家小爷我";
    else if (age < 50) return "大爷我";
    else return "你爷爷我";
    break;
        }
    }
}

//descriptions...

//note, be careful with the size of this list, exp increases as n^3. 
string *exp_level_desc = ({
        BLU "新入道途" NOR, //in unit of year 
        BLU "闻道则喜" NOR, //1x2=2   
        BLU "初领妙道" NOR, //8x2=16
        BLU "略通道行" NOR, //27x2=56    
        HIB "渐入佳境" NOR, //64x2=128
        HIB "元神初具" NOR, //125x2=250
        HIB "道心稳固" NOR, //216x2=432    
        HIB "一日千里" NOR, //343x2=686
        CYN "道高德隆" NOR, //512x2=1024
        CYN "脱胎换骨" NOR, //729x2=1458    
        CYN "霞举飞升" NOR, //1000x2=2000
        CYN "道满根归" NOR, //1331x2=2662    
        HIC "不堕轮回" NOR, //1728x2=3456
        HIC "已证大道" NOR, //2197x2=4394    
        HIC "反璞归真" NOR, //2744x2=5688 
        HIW "天人合一" NOR  //3375x2=6750
});

string *mana_level_desc = ({
        BLU "初具法力" NOR, //    
        BLU "略晓变化" NOR, //1x40=40
        BLU "降龙伏虎" NOR, //4x40=160
        HIB "腾云驾雾" NOR, //9x40=360   
        HIB "神出鬼没" NOR, //16x40=640
        HIB "预知祸福" NOR, //25x40=1000
        HIB "妙领天机" NOR, //36x40=1440    
        CYN "呼风唤雨" NOR, //49x40=1960
        CYN "负海担山" NOR, //64x40=2560    
        CYN "移星换斗" NOR, //81x40=3240
        CYN "包罗万象" NOR, //100x40=4000
        HIC "随心所欲" NOR, //121x40=4840    
        HIC "变换莫测" NOR, //144x40=5760
        HIW "法力无边" NOR  //169x40=6760
});

string *skill_level_desc = ({
        BLU "初学乍练" NOR,
        BLU "初窥门径" NOR,
        BLU "粗通皮毛" NOR,
        HIB "略知一二" NOR,
        HIB "略有所得" NOR,
        HIB "半生不熟" NOR,
        YEL "马马虎虎" NOR,
        YEL "平淡无奇" NOR,
        YEL "平平常常" NOR,
        HIY "心领神会" NOR,
        HIY "触类旁通" NOR,
        HIY "深入浅出" NOR,
        HIM "挥洒自如" NOR,
        HIM "驾轻就熟" NOR,
        HIM "了然于胸" NOR,
        HIR "出类拔萃" NOR,
        HIR "渐入佳境" NOR,
        HIR "豁然贯通" NOR,
        MAG "登峰造极" NOR,
        MAG "出神入化" NOR,
        MAG "神乎其技" NOR,
        CYN "超群绝伦" NOR,
        CYN "独步天下" NOR,
        CYN "卓然大家" NOR,
        HIC "一代宗师" NOR,
        HIC "空前绝后" NOR,
        HIC "旷古绝伦" NOR,
        WHT "震古铄今" NOR,
        WHT "超凡入圣" NOR,
        WHT "返璞归真" NOR,
        HIW "深不可测" NOR
/* from xyj2000
        BLU "初学乍练" NOR,
        BLU "不知所以" NOR,
        BLU "粗通皮毛" NOR,
        HIB "略识之无" NOR,
        HIB "渐有所悟" NOR,
        HIB "半生不熟" NOR,
        YEL "马马虎虎" NOR,
        YEL "平淡无奇" NOR,
        YEL "平平常常" NOR,
        HIY "触类旁通" NOR,
        HIY "心领神会" NOR,
        HIY "深入浅出" NOR,
        HIM "挥洒自如" NOR,
        HIM "驾轻就熟" NOR,
        HIM "出类拔萃" NOR,
        HIR "初入佳境" NOR,
        HIR "神乎其技" NOR,
        HIR "威不可当" NOR,
        MAG "出神入化" NOR,
        MAG "豁然贯通" NOR,
        MAG "超群绝伦" NOR,
        CYN "登峰造极" NOR,
        CYN "卓然大家" NOR,
        CYN "一代宗师" NOR,
        HIC "独步天下" NOR,
        HIC "空前绝后" NOR,
        HIC "旷古绝伦" NOR,
        WHT "震古铄今" NOR,
        WHT "超凡入圣" NOR,
        WHT "返璞归真" NOR,
        HIW "深不可测" NOR
*/
/* /cmds/std/check.c
    BLU "初学乍练" NOR,   BLU "初窥门径" NOR,
    HIB "粗通皮毛" NOR,   HIB "略知一二" NOR,
    YEL "半生不熟" NOR,   YEL "马马虎虎" NOR,
    HIY "已有小成" NOR,   HIY "渐入佳境" NOR,
    HIM "驾轻就熟" NOR,   HIM "了然于胸" NOR,
    HIR "出类拔萃" NOR,   HIR "心领神会" NOR,
    MAG "神乎其技" NOR,   MAG "出神入化" NOR,
    CYN "豁然贯通" NOR,   CYN "登峰造极" NOR,
    HIC "举世无双" NOR,   HIC "一代宗师" NOR,
    HIC "震古铄今" NOR,   HIW "深不可测" NOR
*/
/* /cmds/usr/skills.c
    BLU "初学乍练" NOR,
    BLU "初窥门径" NOR,
    HIB "粗通皮毛" NOR,
    HIB "略知一二" NOR,
    YEL "半生不熟" NOR,
    YEL "马马虎虎" NOR,
    HIY "已有小成" NOR,
    HIY "渐入佳境" NOR,
    HIM "驾轻就熟" NOR,
    HIM "了然于胸" NOR,
    HIR "出类拔萃" NOR,
    HIR "心领神会" NOR,
    MAG "神乎其技" NOR,
    MAG "出神入化" NOR,
    CYN "豁然贯通" NOR,
    CYN "登峰造极" NOR,
    HIC "举世无双" NOR,
    HIC "一代宗师" NOR,
    HIC "震古铄今" NOR,
    HIW "深不可测" NOR
*/
});

string *knowledge_level_desc = ({
        BLU "新学乍用" NOR,
        BLU "不甚了了" NOR,
        HIB "初识端倪" NOR,
        HIB "初窥门径" NOR,
        YEL "略知一二" NOR,
        YEL "茅塞顿开" NOR,
        HIY "马马虎虎" NOR,
        HIY "滚瓜烂熟" NOR,
        HIM "运用自如" NOR,
        HIM "触类旁通" NOR,
        HIR "深入浅出" NOR,
        HIR "已有小成" NOR,
        MAG "心领神会" NOR,
        MAG "了然于胸" NOR,
        CYN "卓尔不群" NOR,
        CYN "满腹经纶" NOR,
        HIC "豁然贯通" NOR,
        HIC "博古通今" NOR,
        WHT "举世无双" NOR,
        WHT "震古铄今" NOR,
        HIW "深不可测" NOR
/* xyj2000
        BLU "新学乍用" NOR,
        BLU "不甚了了" NOR,
        BLU "不知端倪" NOR,
        HIB "平淡无奇" NOR,
        HIB "司空见惯" NOR,
        HIB "初窥门径" NOR,
        YEL "略知一二" NOR,
        YEL "茅塞顿开" NOR,
        YEL "略识之无" NOR,
        HIY "滚瓜烂熟" NOR,
        HIY "马马虎虎" NOR,
        HIY "轻车熟路" NOR,
        HIM "运用自如" NOR,
        HIM "触类旁通" NOR,
        HIM "深入浅出" NOR,
        HIR "已有小成" NOR,
        HIR "心领神会" NOR,
        HIR "了然于胸" NOR,
        MAG "见多识广" NOR,
        MAG "无所不通" NOR,
        MAG "卓尔不群" NOR,
        CYN "满腹经纶" NOR,
        CYN "豁然贯通" NOR,
        CYN "博古通今" NOR,
        HIC "博大精深" NOR,
        HIC "超群绝伦" NOR,
        HIC "举世无双" NOR,
        WHT "独步天下" NOR,
        WHT "震古铄今" NOR,
        WHT "超凡入圣" NOR,
        HIW "深不可测" NOR
*/
/* /cmds/usr/skills.c
        BLU "新学乍用" NOR,
        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        YEL "马马虎虎" NOR,
        YEL "已有小成" NOR,
        CYN "心领神会" NOR,
        CYN "了然于胸" NOR,
        CYN "豁然贯通" NOR,
        HIC "举世无双" NOR,
        HIC "震古铄今" NOR,
        HIW "深不可测" NOR
*/
});

string describe_exp(int value)
{
    int grade, two_year, n;
    
    two_year = value / 2000;
    for (grade = 0; grade < sizeof(exp_level_desc); grade++) {
        n = (grade+1) * (grade+1) * (grade+1);
        if (two_year < n) break;
    }
    if (grade >= sizeof(exp_level_desc))
        grade = sizeof(exp_level_desc) - 1;
    return exp_level_desc[grade];
}

int grade_exp(string desc)
{
    int grade, n;

    for (grade = 0; grade < sizeof(exp_level_desc); grade++) {
        n = grade;
        if (exp_level_desc[grade] == desc)
            return n;
    }
    return 0;
}

string describe_skills(mapping skills)
{
    int grade, lvl, i;
    string *sk;
    if (!sizeof(skills)) return BLU "一窍不通" NOR;
    sk = keys(skills);
    for (i = 0; i < sizeof(sk); i++) {
        if (SKILL_D(sk[i])->type() == "knowledge") continue;
        if (lvl < skills[sk[i]]) lvl = skills[sk[i]];
    }
    grade = lvl / 10;
    if (grade >= sizeof(skill_level_desc))
        grade = sizeof(skill_level_desc) - 1;
    return skill_level_desc[grade];
}

varargs string describe_skill(string skill, int lvl)
{
    int grade;
    string *level_desc;
    
    if (SKILL_D(skill)->type() == "knowledge")
        level_desc = knowledge_level_desc;
    else
        level_desc = skill_level_desc;

    grade = lvl / 10;
    if (grade >= sizeof(level_desc))
        grade = sizeof(level_desc) - 1;
    return level_desc[grade];
}

string describe_force(int value)
{
    int year, sixty, left;
    string line;
    
    year = value / 100;
    sixty = year / 60;
    left = year % 60;

    if (year <= 0) {
        line = HIB "不到一年" NOR;
        return line;
    }
    
    if (sixty > 0)
        if (left != 0)
            line = HIW + chinese_number(sixty) + "甲子" + NOR + "又" +  HIR + chinese_number(left) + "年" + NOR;
        else
            line = HIW + chinese_number(sixty) + "甲子"  + NOR;
    else 
        line = HIR + chinese_number(year)+"年" + NOR;

    return line;
}

string describe_mana(int value)
{
    int grade, lvl, n;

    //in unit of 40, increase by n^2.
    lvl = value / 40;
    for (grade = 0; grade < sizeof(mana_level_desc); grade++) {
        n = (grade+1) * (grade+1);
        if (lvl < n) break;
    }
    if (grade >= sizeof(mana_level_desc))
        grade = sizeof(mana_level_desc) - 1;
    return mana_level_desc[grade];
}
 
int grade_mana(string desc)
{
    int grade;

    for (grade = 0; grade < sizeof(mana_level_desc); grade++) {
        if ((string)mana_level_desc[grade] == desc)
            return grade;
    }
    return 0;
}

string query_description(int type)
{
    int i;
    string *level_desc;
    string line = "";
    
    if (type == 0) level_desc = exp_level_desc;
    else if (type == 1) level_desc = skill_level_desc;
    else if (type == 2) level_desc = knowledge_level_desc;
    else level_desc = mana_level_desc;
    
    for (i = 0; i < sizeof(level_desc); i++) {
        line += level_desc[i] + "    ";
        if ((i%4) == 3) line += "\n";
    }
    
    return line;
}

