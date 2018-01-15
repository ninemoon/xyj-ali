// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by snowcat jan 22 1998

#include <ansi.h>
#include <quest.h>

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "秘笈",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "灾民",   "zai min" ,   "白银(silver)", "5" }), 
// 12000   : ({ "kill",  "白骨精", "baigu jing", "",             "3" });
 
//找一本秘笈，救济灾民五两银子，三打白骨精．．．．．．

mapping quests_armor = ([
      10 : ({ "find", "皮背心",         "pi beixin",          "", "1" }),
      20 : ({ "find", "牛皮盾",         "leather shield",     "", "1" }),
      30 : ({ "find", "藤甲",           "teng jia",           "", "1" }),
      40 : ({ "find", "牛皮靴",         "leather boots",      "", "1" }),
      50 : ({ "find", "花褶靴",         "flower boots",       "", "1" }),
     100 : ({ "find", "兵服",           "cloth",              "", "1" }),
     110 : ({ "find", "皮袍",           "pipao",              "", "1" }),
     200 : ({ "find", "碧水霓裳",       "nichang",            "", "1" }),
    4100 : ({ "find", "虎皮大氅",       "hupi dachang",       "", "1" }),
    4200 : ({ "find", "硬木盔",         "ying mukui",         "", "1" }),
    4300 : ({ "find", "铁盔",           "tie kui",            "", "1" }),
    4400 : ({ "find", "布头巾",         "tou jin",            "", "1" }),
    4500 : ({ "find", "厚牛皮盾",       "houniu pidun",       "", "1" }),
    4600 : ({ "find", "紫绒披风",       "zirong pifeng",      "", "1" }),
    7000 : ({ "find", "犀牛皮衣",       "xiniu piyi",         "", "1" }),
    8000 : ({ "find", "衙役服",         "yayi cloth",         "", "1" }),
    8100 : ({ "find", "犀皮背心",       "xipi beixin",        "", "1" }),
    8200 : ({ "find", "牛皮衣",         "niupi yi",           "", "1" }),
    8300 : ({ "find", "熊皮短袍",       "xiongpi duanpao",    "", "1" }),
    8400 : ({ "find", "虎皮裙",         "hupi qun",           "", "1" }),
    8500 : ({ "find", "狼皮裤",         "langpi qun",         "", "1" }),
    9000 : ({ "find", "战袍",           "zhan pao",           "", "1" }),
   11000 : ({ "find", "铁甲",           "iron armor",         "", "1" }),
   12000 : ({ "find", "雪山白袍",       "baipao",             "", "1" }),
   13000 : ({ "find", "八卦道袍",       "bagua pao",          "", "1" }),
   14000 : ({ "find", "熟铜甲",         "bronze armor",       "", "1" }),
   20000 : ({ "find", "天兵战甲",       "heaven armor",       "", "1" }),
   21000 : ({ "find", "狼皮裙",         "wolf skirt",         "", "1" }),
   22000 : ({ "find", "兽皮裙",         "shoupi qun",         "", "1" }),
   23000 : ({ "find", HIG "芭蕉裙" NOR, "palm skirt",         "", "1" }),
   31000 : ({ "find", "黑罴皮",         "heipi pi",           "", "1" }),
   31500 : ({ "find", "棕熊皮",         "zongxiong pi",       "", "1" }),
   32000 : ({ "find", "青狈皮",         "qingbei pi",         "", "1" }),
   32500 : ({ "find", "猛犸皮",         "mengma pi",          "", "1" }),
   33000 : ({ "find", "铁头靴",         "tie tou xue",        "", "1" }),
   33500 : ({ "find", "铜头靴",         "tong tou xue",       "", "1" }),
   34000 : ({ "find", "铁爪套",         "tie zhua tao",       "", "1" }),
   34500 : ({ "find", "铜爪套",         "tong zhua tao",      "", "1" }),
   35000 : ({ "find", "铁手套",         "tie shou tao",       "", "1" }),
   35500 : ({ "find", "铜手套",         "tong shou tao",      "", "1" }),
   36000 : ({ "find", "铁头盔",         "tie tou kui",        "", "1" }),
   36500 : ({ "find", "铜头盔",         "tong tou kui",       "", "1" }),
   37000 : ({ "find", "铁护肩",         "tie hu jian",        "", "1" }),
   37500 : ({ "find", "铜护肩",         "tong hu jian",       "", "1" }),
   38000 : ({ "find", "铁护腰",         "tie hu yao",         "", "1" }),
   38500 : ({ "find", "铜护腰",         "tong hu yao",        "", "1" }),
   39000 : ({ "find", "铁护腕",         "tie hu wan",         "", "1" }),
   39500 : ({ "find", "铜护腕",         "tong hu wan",        "", "1" }),
   40000 : ({ "find", HIY"护法袈裟"NOR, "jia sha",            "", "1" }),
   41000 : ({ "find", HIY"袈裟"NOR,     "jia sha",            "", "1" }),
   42000 : ({ "find", "牦牛皮",         "maoniu pi",          "", "1" }),
   43000 : ({ "find", "水牛皮",         "shuiniu pi",         "", "1" }),
   44000 : ({ "find", "野象皮",         "yexiang pi",         "", "1" }),
   45000 : ({ "find", "公鹿皮",         "gonglu pi",          "", "1" }),
   46000 : ({ "find", "豺皮",           "chai pi",            "", "1" }),
   47000 : ({ "find", "乌龟甲",         "wugui jia",          "", "1" }),
   48000 : ({ "find", "王八甲",         "wangba jia",         "", "1" }),
   49000 : ({ "find", "千鳞甲",         "qianling jia",       "", "1" }),
   49500 : ({ "find", "巨蟹壳",         "juxie ke",           "", "1" }),
   51000 : ({ "find", "花豹皮",         "huabao pi",          "", "1" }),
   52000 : ({ "find", "白虎皮",         "baihu pi",           "", "1" }),
   53000 : ({ "find", "黑虎皮",         "heihu pi",           "", "1" }),
   54000 : ({ "find", "金狮皮",         "jinshi pi",          "", "1" }),
   55000 : ({ "find", "卷毛狮皮",       "juanmao pi",         "", "1" }),
   56000 : ({ "find", "山猫皮",         "shanmao pi",         "", "1" }),
   57000 : ({ "find", "白铁甲",         "armor",              "", "1" }),
   57001 : ({ "find", "灰铁甲",         "armor",              "", "1" }),
   57002 : ({ "find", "青铁甲",         "armor",              "", "1" }),
   57003 : ({ "find", "锈铁甲",         "armor",              "", "1" }),
   57004 : ({ "find", "乌铁甲",         "armor",              "", "1" }),
   57005 : ({ "find", "黑铁甲",         "armor",              "", "1" }),
   57010 : ({ "find", "白铜甲",         "armor",              "", "1" }),
   57011 : ({ "find", "灰铜甲",         "armor",              "", "1" }),
   57012 : ({ "find", "青铜甲",         "armor",              "", "1" }),
   57013 : ({ "find", "锈铜甲",         "armor",              "", "1" }),
   57014 : ({ "find", "乌铜甲",         "armor",              "", "1" }),
   57015 : ({ "find", "黑铜甲",         "armor",              "", "1" }),
   61000 : ({ "find", "虎皮披风",       "tiger surcoat",      "", "1" }),
   62000 : ({ "find", "青柳藤甲",       "qingliu teng jia",   "", "1" }),
   63000 : ({ "find", "赤柳藤甲",       "chiliu teng jia",    "", "1" }),
   64000 : ({ "find", "紫柳藤甲",       "ziliu teng jia",     "", "1" }),
   65000 : ({ "find", "黑柳藤甲",       "heiliu teng jia",    "", "1" }),
   66000 : ({ "find", "青萝藤盾",       "qingluo dun",        "", "1" }),
   67000 : ({ "find", "紫萝藤盾",       "ziluo dun",          "", "1" }),
   68000 : ({ "find", "樟木盾",         "zhangmu dun",        "", "1" }),
   69000 : ({ "find", "楠木盾",         "nanmu dun",          "", "1" }),
   70000 : ({ "find", "犀牛皮盾",       "xiniupi dun",        "", "1" }),
   71000 : ({ "find", "熊皮盾",         "xiongpi dun",        "", "1" }),
   72000 : ({ "find", "象皮盾",         "xiangpi dun",        "", "1" }),
   73000 : ({ "find", "虎皮盾",         "hupi dun",           "", "1" }),
   77000 : ({ "find", "镶边龙骨甲",     "armor",              "", "1" }),
   77000 : ({ "find", "压花龙骨甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镂花龙骨甲",     "armor",              "", "1" }),
   77000 : ({ "find", "玉柄龙骨甲",     "armor",              "", "1" }),
   77000 : ({ "find", "乌心龙骨甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镶边虎竹甲",     "armor",              "", "1" }),
   77000 : ({ "find", "压花虎竹甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镂花虎竹甲",     "armor",              "", "1" }),
   77000 : ({ "find", "玉柄虎竹甲",     "armor",              "", "1" }),
   77000 : ({ "find", "乌心虎竹甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镶边硬藤甲",     "armor",              "", "1" }),
   77000 : ({ "find", "压花硬藤甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镂花硬藤甲",     "armor",              "", "1" }),
   77000 : ({ "find", "玉柄硬藤甲",     "armor",              "", "1" }),
   77000 : ({ "find", "乌心硬藤甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镶边坚木甲",     "armor",              "", "1" }),
   77000 : ({ "find", "压花坚木甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镂花坚木甲",     "armor",              "", "1" }),
   77000 : ({ "find", "玉柄坚木甲",     "armor",              "", "1" }),
   77000 : ({ "find", "乌心坚木甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镶边龟纹甲",     "armor",              "", "1" }),
   77000 : ({ "find", "压花龟纹甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镂花龟纹甲",     "armor",              "", "1" }),
   77000 : ({ "find", "玉柄龟纹甲",     "armor",              "", "1" }),
   77000 : ({ "find", "乌心龟纹甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镶边灌铅甲",     "armor",              "", "1" }),
   77000 : ({ "find", "压花灌铅甲",     "armor",              "", "1" }),
   77000 : ({ "find", "镂花灌铅甲",     "armor",              "", "1" }),
   77000 : ({ "find", "玉柄灌铅甲",     "armor",              "", "1" }),
   77000 : ({ "find", "乌心灌铅甲",     "armor",              "", "1" }),
   80000 : ({ "find", "银甲",           "yin jia",            "", "1" }),
   80000 : ({ "find", "粉色柳絮护裙",   "skirt",              "", "1" }),
   80001 : ({ "find", "粉色柳絮战裙",   "skirt",              "", "1" }),
   80002 : ({ "find", "粉色丝绒护裙",   "skirt",              "", "1" }),
   80003 : ({ "find", "粉色丝绒战裙",   "skirt",              "", "1" }),
   80004 : ({ "find", "粉色罗纱护裙",   "skirt",              "", "1" }),
   80005 : ({ "find", "粉色罗纱战裙",   "skirt",              "", "1" }),
   80006 : ({ "find", "粉色细纱护裙",   "skirt",              "", "1" }),
   80007 : ({ "find", "粉色细纱战裙",   "skirt",              "", "1" }),
   80008 : ({ "find", "粉色麻纱护裙",   "skirt",              "", "1" }),
   80009 : ({ "find", "粉色麻纱战裙",   "skirt",              "", "1" }),
   80010 : ({ "find", "翡红柳絮护裙",   "skirt",              "", "1" }),
   80011 : ({ "find", "翡红柳絮战裙",   "skirt",              "", "1" }),
   80012 : ({ "find", "翡红丝绒护裙",   "skirt",              "", "1" }),
   80013 : ({ "find", "翡红丝绒战裙",   "skirt",              "", "1" }),
   80014 : ({ "find", "翡红罗纱护裙",   "skirt",              "", "1" }),
   80015 : ({ "find", "翡红罗纱战裙",   "skirt",              "", "1" }),
   80016 : ({ "find", "翡红细纱护裙",   "skirt",              "", "1" }),
   80017 : ({ "find", "翡红细纱战裙",   "skirt",              "", "1" }),
   80018 : ({ "find", "翡红麻纱护裙",   "skirt",              "", "1" }),
   80019 : ({ "find", "翡红麻纱战裙",   "skirt",              "", "1" }),
   80020 : ({ "find", "淡黄柳絮护裙",   "skirt",              "", "1" }),
   80021 : ({ "find", "淡黄柳絮战裙",   "skirt",              "", "1" }),
   80022 : ({ "find", "淡黄丝绒护裙",   "skirt",              "", "1" }),
   80023 : ({ "find", "淡黄丝绒战裙",   "skirt",              "", "1" }),
   80024 : ({ "find", "淡黄罗纱护裙",   "skirt",              "", "1" }),
   80025 : ({ "find", "淡黄罗纱战裙",   "skirt",              "", "1" }),
   80026 : ({ "find", "淡黄细纱护裙",   "skirt",              "", "1" }),
   80027 : ({ "find", "淡黄细纱战裙",   "skirt",              "", "1" }),
   80028 : ({ "find", "淡黄麻纱护裙",   "skirt",              "", "1" }),
   80029 : ({ "find", "淡黄麻纱战裙",   "skirt",              "", "1" }),
   80030 : ({ "find", "鹅黄柳絮护裙",   "skirt",              "", "1" }),
   80031 : ({ "find", "鹅黄柳絮战裙",   "skirt",              "", "1" }),
   80032 : ({ "find", "鹅黄丝绒护裙",   "skirt",              "", "1" }),
   80033 : ({ "find", "鹅黄丝绒战裙",   "skirt",              "", "1" }),
   80034 : ({ "find", "鹅黄罗纱护裙",   "skirt",              "", "1" }),
   80035 : ({ "find", "鹅黄罗纱战裙",   "skirt",              "", "1" }),
   80036 : ({ "find", "鹅黄细纱护裙",   "skirt",              "", "1" }),
   80037 : ({ "find", "鹅黄细纱战裙",   "skirt",              "", "1" }),
   80038 : ({ "find", "鹅黄麻纱护裙",   "skirt",              "", "1" }),
   80039 : ({ "find", "鹅黄麻纱战裙",   "skirt",              "", "1" }),
   80040 : ({ "find", "紫花柳絮护裙",   "skirt",              "", "1" }),
   80041 : ({ "find", "紫花柳絮战裙",   "skirt",              "", "1" }),
   80042 : ({ "find", "紫花丝绒护裙",   "skirt",              "", "1" }),
   80043 : ({ "find", "紫花丝绒战裙",   "skirt",              "", "1" }),
   80044 : ({ "find", "紫花罗纱护裙",   "skirt",              "", "1" }),
   80045 : ({ "find", "紫花罗纱战裙",   "skirt",              "", "1" }),
   80046 : ({ "find", "紫花细纱护裙",   "skirt",              "", "1" }),
   80047 : ({ "find", "紫花细纱战裙",   "skirt",              "", "1" }),
   80048 : ({ "find", "紫花麻纱护裙",   "skirt",              "", "1" }),
   80049 : ({ "find", "紫花麻纱战裙",   "skirt",              "", "1" }),
   81000 : ({ "find", "彩贝甲",         "color shell",        "", "1" }),
   90000 : ({ "find", "太极道袍",       "cloth",              "", "1" }),
  100000 : ({ "find", "亮银甲",         "silver armor",       "", "1" }),
  110000 : ({ "find", "烟里火比甲",     "smoky armor",        "", "1" }),
  120000 : ({ "find", "渌水罗衣",       "fancy skirt",        "", "1" }),
  200000 : ({ "find", "白罗袍",         "baipao",             "", "1" }),
  210000 : ({ "find", "八卦道袍",       "bagua pao",          "", "1" }),
  220000 : ({ "find", "金环锁子甲",     "golden armor",       "", "1" }),
  300000 : ({ "find", "降魔袍",         "xiangmo pao",        "", "1" }),
  310000 : ({ "find", "锦绣战袍",       "zhanpao",            "", "1" }),
  320000 : ({ "find", "黄虎皮",         "huang hupi",         "", "1" }),
  330000 : ({ "find", "兽皮披风",       "shoupi pifeng",      "", "1" }),
  550000 : ({ "find", HIY"蟒龙袍"NOR,   "long pao",           "", "1" }),
  700000 : ({ "find", "大红蟒袍",       "mangpao",            "", "1" }),
  800000 : ({ "find", HIY "蟒龙袍" NOR, "long pao",           "", "1" }),
 2000000 : ({ "find", HIY"五彩天衣"NOR, "tian yi",            "", "1" }),
 2100000 : ({ "find", "皂罗袍",         "purple cloth",       "", "1" }),
 2200000 : ({ "find", HIY"锦镧袈裟"NOR, "jinlan jiasha",      "", "1" }),
]);


