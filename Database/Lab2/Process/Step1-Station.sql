drop table Database1;
drop table Possible_Ticket;
drop table Remaining_Ticket;
drop table Order_Table;
drop table Client;
drop table Adminisitrator;
drop table Train;
drop table Station;
drop table The_Date;
create table Station
(
  Station_Name varchar(200),
  City_Name varchar(200),
  Station_ID integer,
  primary key(Station_ID)
);
insert into Station (Station_Name, City_Name, Station_ID)
values ('一步滩', '一步滩', 1);
insert into Station (Station_Name, City_Name, Station_ID)
values ('一间堡', '一间堡', 2);
insert into Station (Station_Name, City_Name, Station_ID)
values ('一面坡', '一面坡', 3);
insert into Station (Station_Name, City_Name, Station_ID)
values ('一面山', '一面山', 4);
insert into Station (Station_Name, City_Name, Station_ID)
values ('七台河', '七台河', 5);
insert into Station (Station_Name, City_Name, Station_ID)
values ('七甸', '七甸', 6);
insert into Station (Station_Name, City_Name, Station_ID)
values ('七苏木', '七苏木', 7);
insert into Station (Station_Name, City_Name, Station_ID)
values ('七营', '七营', 8);
insert into Station (Station_Name, City_Name, Station_ID)
values ('七龙星', '七龙星', 9);
insert into Station (Station_Name, City_Name, Station_ID)
values ('万乐', '万乐', 10);
insert into Station (Station_Name, City_Name, Station_ID)
values ('万发屯', '万发屯', 11);
insert into Station (Station_Name, City_Name, Station_ID)
values ('万宁', '万宁', 12);
insert into Station (Station_Name, City_Name, Station_ID)
values ('万州', '万州', 13);
insert into Station (Station_Name, City_Name, Station_ID)
values ('万年', '万年', 14);
insert into Station (Station_Name, City_Name, Station_ID)
values ('万庄', '万庄', 15);
insert into Station (Station_Name, City_Name, Station_ID)
values ('万源', '万源', 16);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三义井', '三义井', 17);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三井子', '三井子', 18);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三亚', '三亚', 19);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三元坝', '三元坝', 20);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三关口', '三关口', 21);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三十家', '三十家', 22);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三十里堡', '三十里堡', 23);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三原', '三原', 24);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三合庄', '三合庄', 25);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三堂集', '三堂集', 26);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三家子', '三家子', 27);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三家寨', '三家寨', 28);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三家店', '三家店', 29);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三把火', '三把火', 30);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三明北', '三明北', 31);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三水', '三水', 32);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三水北', '三水', 33);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三水南', '三水', 34);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三汇镇', '三汇镇', 35);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三江', '三江', 36);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三江南', '三江南', 37);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三江县', '三江县', 38);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三江口', '三江口', 39);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三河县', '三河县', 40);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三源浦', '三源浦', 41);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三穗', '三穗', 42);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三花石', '三花石', 43);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三营', '三营', 44);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三道湖', '三道湖', 45);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三道营', '三道营', 46);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三都县', '三都县', 47);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三门县', '三门县', 48);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三门峡', '三门峡', 49);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三门峡西', '三门峡', 50);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三间房', '三间房', 51);
insert into Station (Station_Name, City_Name, Station_ID)
values ('三阳川', '三阳川', 52);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上万', '上万', 53);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上园', '上园', 54);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上店', '上店', 55);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上普雄', '上普雄', 56);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上板城', '上板城', 57);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上板城南', '上板城', 58);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上海', '上海', 59);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上海南', '上海', 60);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上海虹桥', '上海', 61);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上海西', '上海', 62);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上腰墩', '上腰墩', 63);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上虞', '上虞', 64);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上虞北', '上虞', 65);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上西铺', '上西铺', 66);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上谷', '上谷', 67);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上饶', '上饶', 68);
insert into Station (Station_Name, City_Name, Station_ID)
values ('上高镇', '上高镇', 69);
insert into Station (Station_Name, City_Name, Station_ID)
values ('下台子', '下台子', 70);
insert into Station (Station_Name, City_Name, Station_ID)
values ('下坑子', '下坑子', 71);
insert into Station (Station_Name, City_Name, Station_ID)
values ('下城子', '下城子', 72);
insert into Station (Station_Name, City_Name, Station_ID)
values ('下普雄', '下普雄', 73);
insert into Station (Station_Name, City_Name, Station_ID)
values ('下板城', '下板城', 74);
insert into Station (Station_Name, City_Name, Station_ID)
values ('下社', '下社', 75);
insert into Station (Station_Name, City_Name, Station_ID)
values ('下花园', '下花园', 76);
insert into Station (Station_Name, City_Name, Station_ID)
values ('下马塘', '下马塘', 77);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东丰', '东丰', 78);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东乡', '东乡', 79);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东二道河', '东二道河', 80);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东京城', '东京城', 81);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东元庆', '东元庆', 82);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东光', '东光', 83);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东兴', '东兴', 84);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东升', '东升', 85);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东南营子', '东南营子', 86);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东台', '东台', 87);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东坡', '东坡', 88);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东大坝', '东大坝', 89);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东安东', '东安东', 90);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东富', '东富', 91);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东庄', '东庄', 92);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东戴河', '东戴河', 93);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东方', '东方', 94);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东方红', '东方红', 95);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东明县', '东明县', 96);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东明村', '东明村', 97);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东来', '东来', 98);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东沟门', '东沟门', 99);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东津', '东津', 100);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东海', '东海', 101);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东海县', '东海县', 102);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东淤地', '东淤地', 103);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东港北', '东港北', 104);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东湾', '东湾', 105);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东田良', '东田良', 106);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东胜西', '东胜西', 107);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东至', '东至', 108);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东莞', '东莞', 109);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东莞东', '东莞', 110);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东营南', '东营南', 111);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东营子', '东营子', 112);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东辛庄', '东辛庄', 113);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东边井', '东边井', 114);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东通化', '东通化', 115);
insert into Station (Station_Name, City_Name, Station_ID)
values ('东镇', '东镇', 116);
insert into Station (Station_Name, City_Name, Station_ID)
values ('两家', '两家', 117);
insert into Station (Station_Name, City_Name, Station_ID)
values ('两当', '两当', 118);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中兴', '中兴', 119);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中卫', '中卫', 120);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中台子', '中台子', 121);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中和', '中和', 122);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中嘴', '中嘴', 123);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中宁', '中宁', 124);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中宁东', '中宁', 125);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中宁南', '中宁', 126);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中寨', '中寨', 127);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中山', '中山', 128);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中山北', '中山', 129);
insert into Station (Station_Name, City_Name, Station_ID)
values ('中川机场', '中川机场', 130);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丰乐镇', '丰乐镇', 131);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丰城', '丰城', 132);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丰城南', '丰城', 133);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丰广', '丰广', 134);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丰水村', '丰水村', 135);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丰都', '丰都', 136);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丰镇', '丰镇', 137);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丰顺', '丰顺', 138);
insert into Station (Station_Name, City_Name, Station_ID)
values ('串子沟', '串子沟', 139);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临城', '临城', 140);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临江场', '临江场', 141);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临江溪', '临江溪', 142);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临汾', '临汾', 143);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临汾西', '临汾', 144);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临沂', '临沂', 145);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临沂北', '临沂', 146);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临河', '临河', 147);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临泽', '临泽', 148);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临泽南', '临泽', 149);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临海', '临海', 150);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临清', '临清', 151);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临湘', '临湘', 152);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临西', '临西', 153);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临颍', '临颍', 154);
insert into Station (Station_Name, City_Name, Station_ID)
values ('临高南', '临高南', 155);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丹东', '丹东', 156);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丹东西', '丹东', 157);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丹凤', '丹凤', 158);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丹徒', '丹徒', 159);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丹阳', '丹阳', 160);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丹阳北', '丹阳', 161);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丹霞山', '丹霞山', 162);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丽水', '丽水', 163);
insert into Station (Station_Name, City_Name, Station_ID)
values ('丽江', '丽江', 164);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乃林', '乃林', 165);
insert into Station (Station_Name, City_Name, Station_ID)
values ('义乌', '义乌', 166);
insert into Station (Station_Name, City_Name, Station_ID)
values ('义县', '义县', 167);
insert into Station (Station_Name, City_Name, Station_ID)
values ('义马', '义马', 168);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌伊岭', '乌伊岭', 169);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌兰', '乌兰', 170);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌兰哈达', '乌兰哈达', 171);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌兰浩特', '乌兰浩特', 172);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌兰胡同', '乌兰胡同', 173);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌兰花', '乌兰花', 174);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌固诺尔', '乌固诺尔', 175);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌奴耳', '乌奴耳', 176);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌尔旗汗', '乌尔旗汗', 177);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌拉山', '乌拉山', 178);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌拉特前旗', '乌拉特前旗', 179);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌海', '乌海', 180);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌海北', '乌海', 181);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌海西', '乌海', 182);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌西', '乌西', 183);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌鲁布铁', '乌鲁布铁', 184);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌鲁木齐', '乌鲁木齐', 185);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌鲁木齐南', '乌鲁木齐', 186);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乌龙泉南', '乌龙泉南', 187);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐东', '乐东', 188);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐善村', '乐善村', 189);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐山', '乐山', 190);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐山北', '乐山', 191);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐平市', '乐平市', 192);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐昌', '乐昌', 193);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐武', '乐武', 194);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐清', '乐清', 195);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐跃', '乐跃', 196);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐都', '乐都', 197);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乐都南', '乐都', 198);
insert into Station (Station_Name, City_Name, Station_ID)
values ('九三', '九三', 199);
insert into Station (Station_Name, City_Name, Station_ID)
values ('九台', '九台', 200);
insert into Station (Station_Name, City_Name, Station_ID)
values ('九台南', '九台', 201);
insert into Station (Station_Name, City_Name, Station_ID)
values ('九江', '九江', 202);
insert into Station (Station_Name, City_Name, Station_ID)
values ('九营', '九营', 203);
insert into Station (Station_Name, City_Name, Station_ID)
values ('九龙', '九龙', 204);
insert into Station (Station_Name, City_Name, Station_ID)
values ('九龙塘', '九龙塘', 205);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乳山', '乳山', 206);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乾县', '乾县', 207);
insert into Station (Station_Name, City_Name, Station_ID)
values ('乾安', '乾安', 208);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二井', '二井', 209);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二岔', '二岔', 210);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二营', '二营', 211);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二连', '二连', 212);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二道桥', '二道桥', 213);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二道沟', '二道沟', 214);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二道沟门', '二道沟门', 215);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二道湾', '二道湾', 216);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二龙', '二龙', 217);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二龙屯', '二龙屯', 218);
insert into Station (Station_Name, City_Name, Station_ID)
values ('二龙山屯', '二龙山屯', 219);
insert into Station (Station_Name, City_Name, Station_ID)
values ('于家堡', '于家堡', 220);
insert into Station (Station_Name, City_Name, Station_ID)
values ('于都', '于都', 221);
insert into Station (Station_Name, City_Name, Station_ID)
values ('云东海', '云东海', 222);
insert into Station (Station_Name, City_Name, Station_ID)
values ('云居寺', '云居寺', 223);
insert into Station (Station_Name, City_Name, Station_ID)
values ('云山', '云山', 224);
insert into Station (Station_Name, City_Name, Station_ID)
values ('云彩岭', '云彩岭', 225);
insert into Station (Station_Name, City_Name, Station_ID)
values ('云梦', '云梦', 226);
insert into Station (Station_Name, City_Name, Station_ID)
values ('云浮东', '云浮东', 227);
insert into Station (Station_Name, City_Name, Station_ID)
values ('云霄', '云霄', 228);
insert into Station (Station_Name, City_Name, Station_ID)
values ('互助', '互助', 229);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五十家子', '五十家子', 230);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五原', '五原', 231);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五叉沟', '五叉沟', 232);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五台山', '五台山', 233);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五大连池', '五大连池', 234);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五女山', '五女山', 235);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五家', '五家', 236);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五寨', '五寨', 237);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五常', '五常', 238);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五府山', '五府山', 239);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五林', '五林', 240);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五棵树', '五棵树', 241);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五莲', '五莲', 242);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五营', '五营', 243);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五道沟', '五道沟', 244);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五道河', '五道河', 245);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五龙背', '五龙背', 246);
insert into Station (Station_Name, City_Name, Station_ID)
values ('五龙背东', '五龙背', 247);
insert into Station (Station_Name, City_Name, Station_ID)
values ('井冈山', '井冈山', 248);
insert into Station (Station_Name, City_Name, Station_ID)
values ('井南', '井南', 249);
insert into Station (Station_Name, City_Name, Station_ID)
values ('井店', '井店', 250);
insert into Station (Station_Name, City_Name, Station_ID)
values ('井陉', '井陉', 251);
insert into Station (Station_Name, City_Name, Station_ID)
values ('亚复', '亚复', 252);
insert into Station (Station_Name, City_Name, Station_ID)
values ('亚布力', '亚布力', 253);
insert into Station (Station_Name, City_Name, Station_ID)
values ('亚布力南', '亚布力', 254);
insert into Station (Station_Name, City_Name, Station_ID)
values ('亚沟', '亚沟', 255);
insert into Station (Station_Name, City_Name, Station_ID)
values ('亚河', '亚河', 256);
insert into Station (Station_Name, City_Name, Station_ID)
values ('亚龙湾', '亚龙湾', 257);
insert into Station (Station_Name, City_Name, Station_ID)
values ('交城', '交城', 258);
insert into Station (Station_Name, City_Name, Station_ID)
values ('京山', '京山', 259);
insert into Station (Station_Name, City_Name, Station_ID)
values ('亭亮', '亭亮', 260);
insert into Station (Station_Name, City_Name, Station_ID)
values ('亳州', '亳州', 261);
insert into Station (Station_Name, City_Name, Station_ID)
values ('什里店', '什里店', 262);
insert into Station (Station_Name, City_Name, Station_ID)
values ('仁布', '仁布', 263);
insert into Station (Station_Name, City_Name, Station_ID)
values ('介休', '介休', 264);
insert into Station (Station_Name, City_Name, Station_ID)
values ('介休东', '介休', 265);
insert into Station (Station_Name, City_Name, Station_ID)
values ('从江', '从江', 266);
insert into Station (Station_Name, City_Name, Station_ID)
values ('仙人桥', '仙人桥', 267);
insert into Station (Station_Name, City_Name, Station_ID)
values ('仙林', '仙林', 268);
insert into Station (Station_Name, City_Name, Station_ID)
values ('仙桃西', '仙桃西', 269);
insert into Station (Station_Name, City_Name, Station_ID)
values ('仙游', '仙游', 270);
insert into Station (Station_Name, City_Name, Station_ID)
values ('代县', '代县', 271);
insert into Station (Station_Name, City_Name, Station_ID)
values ('代湾', '代湾', 272);
insert into Station (Station_Name, City_Name, Station_ID)
values ('仲恺', '仲恺', 273);
insert into Station (Station_Name, City_Name, Station_ID)
values ('任丘', '任丘', 274);
insert into Station (Station_Name, City_Name, Station_ID)
values ('任家店', '任家店', 275);
insert into Station (Station_Name, City_Name, Station_ID)
values ('伊和恩格拉', '伊和恩格拉', 276);
insert into Station (Station_Name, City_Name, Station_ID)
values ('伊图里河', '伊图里河', 277);
insert into Station (Station_Name, City_Name, Station_ID)
values ('伊宁', '伊宁', 278);
insert into Station (Station_Name, City_Name, Station_ID)
values ('伊宁东', '伊宁', 279);
insert into Station (Station_Name, City_Name, Station_ID)
values ('伊拉哈', '伊拉哈', 280);
insert into Station (Station_Name, City_Name, Station_ID)
values ('伊敏', '伊敏', 281);
insert into Station (Station_Name, City_Name, Station_ID)
values ('伊春', '伊春', 282);
insert into Station (Station_Name, City_Name, Station_ID)
values ('会同', '会同', 283);
insert into Station (Station_Name, City_Name, Station_ID)
values ('会昌北', '会昌北', 284);
insert into Station (Station_Name, City_Name, Station_ID)
values ('低庄', '低庄', 285);
insert into Station (Station_Name, City_Name, Station_ID)
values ('低窝铺', '低窝铺', 286);
insert into Station (Station_Name, City_Name, Station_ID)
values ('余姚', '余姚', 287);
insert into Station (Station_Name, City_Name, Station_ID)
values ('余姚北', '余姚', 288);
insert into Station (Station_Name, City_Name, Station_ID)
values ('余杭', '余杭', 289);
insert into Station (Station_Name, City_Name, Station_ID)
values ('余江', '余江', 290);
insert into Station (Station_Name, City_Name, Station_ID)
values ('余粮堡', '余粮堡', 291);
insert into Station (Station_Name, City_Name, Station_ID)
values ('佛山', '佛山', 292);
insert into Station (Station_Name, City_Name, Station_ID)
values ('佛岭', '佛岭', 293);
insert into Station (Station_Name, City_Name, Station_ID)
values ('佟家', '佟家', 294);
insert into Station (Station_Name, City_Name, Station_ID)
values ('佳木斯', '佳木斯', 295);
insert into Station (Station_Name, City_Name, Station_ID)
values ('依安', '依安', 296);
insert into Station (Station_Name, City_Name, Station_ID)
values ('侯马', '侯马', 297);
insert into Station (Station_Name, City_Name, Station_ID)
values ('侯马西', '侯马', 298);
insert into Station (Station_Name, City_Name, Station_ID)
values ('保健', '保健', 299);
insert into Station (Station_Name, City_Name, Station_ID)
values ('保定', '保定', 300);
insert into Station (Station_Name, City_Name, Station_ID)
values ('保定东', '保定', 301);
insert into Station (Station_Name, City_Name, Station_ID)
values ('保家楼', '保家楼', 302);
insert into Station (Station_Name, City_Name, Station_ID)
values ('保康', '保康', 303);
insert into Station (Station_Name, City_Name, Station_ID)
values ('俞冲', '俞冲', 304);
insert into Station (Station_Name, City_Name, Station_ID)
values ('信丰', '信丰', 305);
insert into Station (Station_Name, City_Name, Station_ID)
values ('信宜', '信宜', 306);
insert into Station (Station_Name, City_Name, Station_ID)
values ('信阳', '信阳', 307);
insert into Station (Station_Name, City_Name, Station_ID)
values ('信阳东', '信阳', 308);
insert into Station (Station_Name, City_Name, Station_ID)
values ('修武', '修武', 309);
insert into Station (Station_Name, City_Name, Station_ID)
values ('修武西', '修武', 310);
insert into Station (Station_Name, City_Name, Station_ID)
values ('倭肯', '倭肯', 311);
insert into Station (Station_Name, City_Name, Station_ID)
values ('偃师', '偃师', 312);
insert into Station (Station_Name, City_Name, Station_ID)
values ('偏岭', '偏岭', 313);
insert into Station (Station_Name, City_Name, Station_ID)
values ('元宝山', '元宝山', 314);
insert into Station (Station_Name, City_Name, Station_ID)
values ('元氏', '元氏', 315);
insert into Station (Station_Name, City_Name, Station_ID)
values ('元田坝', '元田坝', 316);
insert into Station (Station_Name, City_Name, Station_ID)
values ('元谋', '元谋', 317);
insert into Station (Station_Name, City_Name, Station_ID)
values ('光山', '光山', 318);
insert into Station (Station_Name, City_Name, Station_ID)
values ('光明', '光明', 319);
insert into Station (Station_Name, City_Name, Station_ID)
values ('光明城', '光明城', 320);
insert into Station (Station_Name, City_Name, Station_ID)
values ('光泽', '光泽', 321);
insert into Station (Station_Name, City_Name, Station_ID)
values ('克一河', '克一河', 322);
insert into Station (Station_Name, City_Name, Station_ID)
values ('克东', '克东', 323);
insert into Station (Station_Name, City_Name, Station_ID)
values ('克山', '克山', 324);
insert into Station (Station_Name, City_Name, Station_ID)
values ('克拉玛依', '克拉玛依', 325);
insert into Station (Station_Name, City_Name, Station_ID)
values ('免渡河', '免渡河', 326);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兑镇', '兑镇', 327);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兖州', '兖州', 328);
insert into Station (Station_Name, City_Name, Station_ID)
values ('全州南', '全州南', 329);
insert into Station (Station_Name, City_Name, Station_ID)
values ('全椒', '全椒', 330);
insert into Station (Station_Name, City_Name, Station_ID)
values ('八仙筒', '八仙筒', 331);
insert into Station (Station_Name, City_Name, Station_ID)
values ('八方', '八方', 332);
insert into Station (Station_Name, City_Name, Station_ID)
values ('八苏木', '八苏木', 333);
insert into Station (Station_Name, City_Name, Station_ID)
values ('八虎力', '八虎力', 334);
insert into Station (Station_Name, City_Name, Station_ID)
values ('八角台', '八角台', 335);
insert into Station (Station_Name, City_Name, Station_ID)
values ('八面城', '八面城', 336);
insert into Station (Station_Name, City_Name, Station_ID)
values ('八面通', '八面通', 337);
insert into Station (Station_Name, City_Name, Station_ID)
values ('公主埂', '公主埂', 338);
insert into Station (Station_Name, City_Name, Station_ID)
values ('公主岭', '公主岭', 339);
insert into Station (Station_Name, City_Name, Station_ID)
values ('公主岭南', '公主岭', 340);
insert into Station (Station_Name, City_Name, Station_ID)
values ('公庙子', '公庙子', 341);
insert into Station (Station_Name, City_Name, Station_ID)
values ('公积坂', '公积坂', 342);
insert into Station (Station_Name, City_Name, Station_ID)
values ('公营子', '公营子', 343);
insert into Station (Station_Name, City_Name, Station_ID)
values ('六合镇', '六合镇', 344);
insert into Station (Station_Name, City_Name, Station_ID)
values ('六地沟', '六地沟', 345);
insert into Station (Station_Name, City_Name, Station_ID)
values ('六安', '六安', 346);
insert into Station (Station_Name, City_Name, Station_ID)
values ('六枝', '六枝', 347);
insert into Station (Station_Name, City_Name, Station_ID)
values ('六盘山', '六盘山', 348);
insert into Station (Station_Name, City_Name, Station_ID)
values ('六盘水', '六盘水', 349);
insert into Station (Station_Name, City_Name, Station_ID)
values ('六道河', '六道河', 350);
insert into Station (Station_Name, City_Name, Station_ID)
values ('六道河子', '六道河子', 351);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰家屯', '兰家屯', 352);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰岗', '兰岗', 353);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰岭', '兰岭', 354);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰州', '兰州', 355);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰州东', '兰州', 356);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰州新区', '兰州新区', 357);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰州西', '兰州', 358);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰棱', '兰棱', 359);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰溪', '兰溪', 360);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰考', '兰考', 361);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兰陵北', '兰陵北', 362);
insert into Station (Station_Name, City_Name, Station_ID)
values ('共和', '共和', 363);
insert into Station (Station_Name, City_Name, Station_ID)
values ('共青城', '共青城', 364);
insert into Station (Station_Name, City_Name, Station_ID)
values ('关寨', '关寨', 365);
insert into Station (Station_Name, City_Name, Station_ID)
values ('关村坝', '关村坝', 366);
insert into Station (Station_Name, City_Name, Station_ID)
values ('关林', '关林', 367);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴义', '兴义', 368);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴凯', '兴凯', 369);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴和', '兴和', 370);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴和西', '兴和', 371);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴国', '兴国', 372);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴城', '兴城', 373);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴宁', '兴宁', 374);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴安北', '兴安北', 375);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴安岭', '兴安岭', 376);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴平', '兴平', 377);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴泉堡', '兴泉堡', 378);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴福', '兴福', 379);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴莲', '兴莲', 380);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴隆县', '兴隆县', 381);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴隆店', '兴隆店', 382);
insert into Station (Station_Name, City_Name, Station_ID)
values ('兴隆镇', '兴隆镇', 383);
insert into Station (Station_Name, City_Name, Station_ID)
values ('内乡', '内乡', 384);
insert into Station (Station_Name, City_Name, Station_ID)
values ('内江', '内江', 385);
insert into Station (Station_Name, City_Name, Station_ID)
values ('内江北', '内江', 386);
insert into Station (Station_Name, City_Name, Station_ID)
values ('内江南', '内江', 387);
insert into Station (Station_Name, City_Name, Station_ID)
values ('册亨', '册亨', 388);
insert into Station (Station_Name, City_Name, Station_ID)
values ('冕宁', '冕宁', 389);
insert into Station (Station_Name, City_Name, Station_ID)
values ('冕山', '冕山', 390);
insert into Station (Station_Name, City_Name, Station_ID)
values ('军粮城北', '军粮城北', 391);
insert into Station (Station_Name, City_Name, Station_ID)
values ('农安', '农安', 392);
insert into Station (Station_Name, City_Name, Station_ID)
values ('冠豸山', '冠豸山', 393);
insert into Station (Station_Name, City_Name, Station_ID)
values ('冯家山', '冯家山', 394);
insert into Station (Station_Name, City_Name, Station_ID)
values ('冯屯', '冯屯', 395);
insert into Station (Station_Name, City_Name, Station_ID)
values ('冷水江东', '冷水江东', 396);
insert into Station (Station_Name, City_Name, Station_ID)
values ('准沙日乌苏', '准沙日乌苏', 397);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凉红', '凉红', 398);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凌海', '凌海', 399);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凌源', '凌源', 400);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凌源东', '凌源', 401);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凤凰城', '凤凰城', 402);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凤凰机场', '凤凰机场', 403);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凤县', '凤县', 404);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凤城东', '凤城东', 405);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凤州', '凤州', 406);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凤翔', '凤翔', 407);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凭祥', '凭祥', 408);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凯北', '凯北', 409);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凯里', '凯里', 410);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凯里南', '凯里', 411);
insert into Station (Station_Name, City_Name, Station_ID)
values ('凯里西', '凯里', 412);
insert into Station (Station_Name, City_Name, Station_ID)
values ('刀尔登', '刀尔登', 413);
insert into Station (Station_Name, City_Name, Station_ID)
values ('刁家段', '刁家段', 414);
insert into Station (Station_Name, City_Name, Station_ID)
values ('分宜', '分宜', 415);
insert into Station (Station_Name, City_Name, Station_ID)
values ('刘家店', '刘家店', 416);
insert into Station (Station_Name, City_Name, Station_ID)
values ('刘家河', '刘家河', 417);
insert into Station (Station_Name, City_Name, Station_ID)
values ('刘沟', '刘沟', 418);
insert into Station (Station_Name, City_Name, Station_ID)
values ('利川', '利川', 419);
insert into Station (Station_Name, City_Name, Station_ID)
values ('到保', '到保', 420);
insert into Station (Station_Name, City_Name, Station_ID)
values ('前山', '前山', 421);
insert into Station (Station_Name, City_Name, Station_ID)
values ('前磨头', '前磨头', 422);
insert into Station (Station_Name, City_Name, Station_ID)
values ('前窑', '前窑', 423);
insert into Station (Station_Name, City_Name, Station_ID)
values ('前苇塘', '前苇塘', 424);
insert into Station (Station_Name, City_Name, Station_ID)
values ('前进镇', '前进镇', 425);
insert into Station (Station_Name, City_Name, Station_ID)
values ('前锋', '前锋', 426);
insert into Station (Station_Name, City_Name, Station_ID)
values ('加劳', '加劳', 427);
insert into Station (Station_Name, City_Name, Station_ID)
values ('加南', '加南', 428);
insert into Station (Station_Name, City_Name, Station_ID)
values ('加格达奇', '加格达奇', 429);
insert into Station (Station_Name, City_Name, Station_ID)
values ('励家', '励家', 430);
insert into Station (Station_Name, City_Name, Station_ID)
values ('劲松', '劲松', 431);
insert into Station (Station_Name, City_Name, Station_ID)
values ('劳动屯', '劳动屯', 432);
insert into Station (Station_Name, City_Name, Station_ID)
values ('勃利', '勃利', 433);
insert into Station (Station_Name, City_Name, Station_ID)
values ('勉县', '勉县', 434);
insert into Station (Station_Name, City_Name, Station_ID)
values ('包头', '包头', 435);
insert into Station (Station_Name, City_Name, Station_ID)
values ('包头东', '包头', 436);
insert into Station (Station_Name, City_Name, Station_ID)
values ('包头北', '包头', 437);
insert into Station (Station_Name, City_Name, Station_ID)
values ('包头西', '包头', 438);
insert into Station (Station_Name, City_Name, Station_ID)
values ('化处', '化处', 439);
insert into Station (Station_Name, City_Name, Station_ID)
values ('化州', '化州', 440);
insert into Station (Station_Name, City_Name, Station_ID)
values ('化德', '化德', 441);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北井子', '北井子', 442);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北京', '北京', 443);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北京东', '北京', 444);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北京北', '北京', 445);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北京南', '北京', 446);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北京西', '北京', 447);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北兴安', '北兴安', 448);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北台子', '北台子', 449);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北宅', '北宅', 450);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北安', '北安', 451);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北屯', '北屯', 452);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北屯市', '北屯市', 453);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北岗', '北岗', 454);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北戴河', '北戴河', 455);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北板桥', '北板桥', 456);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北流', '北流', 457);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北海', '北海', 458);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北滘', '北滘', 459);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北碚', '北碚', 460);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北磴', '北磴', 461);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北票南', '北票南', 462);
insert into Station (Station_Name, City_Name, Station_ID)
values ('北马圈子', '北马圈子', 463);
insert into Station (Station_Name, City_Name, Station_ID)
values ('十八台', '十八台', 464);
insert into Station (Station_Name, City_Name, Station_ID)
values ('十堰', '十堰', 465);
insert into Station (Station_Name, City_Name, Station_ID)
values ('十渡', '十渡', 466);
insert into Station (Station_Name, City_Name, Station_ID)
values ('十里坪', '十里坪', 467);
insert into Station (Station_Name, City_Name, Station_ID)
values ('千河', '千河', 468);
insert into Station (Station_Name, City_Name, Station_ID)
values ('千阳', '千阳', 469);
insert into Station (Station_Name, City_Name, Station_ID)
values ('升昌', '升昌', 470);
insert into Station (Station_Name, City_Name, Station_ID)
values ('午汲', '午汲', 471);
insert into Station (Station_Name, City_Name, Station_ID)
values ('半截河', '半截河', 472);
insert into Station (Station_Name, City_Name, Station_ID)
values ('华城', '华城', 473);
insert into Station (Station_Name, City_Name, Station_ID)
values ('华山', '华山', 474);
insert into Station (Station_Name, City_Name, Station_ID)
values ('华山北', '华山', 475);
insert into Station (Station_Name, City_Name, Station_ID)
values ('华蓥', '华蓥', 476);
insert into Station (Station_Name, City_Name, Station_ID)
values ('卓资东', '卓资东', 477);
insert into Station (Station_Name, City_Name, Station_ID)
values ('卓资山', '卓资山', 478);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南丰', '南丰', 479);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南丹', '南丹', 480);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南京', '南京', 481);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南京南', '南京', 482);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南仇', '南仇', 483);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南充', '南充', 484);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南充北', '南充', 485);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南兴安', '南兴安', 486);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南华', '南华', 487);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南博山', '南博山', 488);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南口', '南口', 489);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南口前', '南口前', 490);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南召', '南召', 491);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南城', '南城', 492);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南城司', '南城司', 493);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南大庙', '南大庙', 494);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南头', '南头', 495);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南宁', '南宁', 496);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南宁东', '南宁', 497);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南宁西', '南宁', 498);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南宫东', '南宫东', 499);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南尔岗', '南尔岗', 500);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南岔', '南岔', 501);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南峪', '南峪', 502);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南平北', '南平', 503);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南平南', '南平', 504);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南昌', '南昌', 505);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南昌西', '南昌', 506);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南曹', '南曹', 507);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南朗', '南朗', 508);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南木', '南木', 509);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南杂木', '南杂木', 510);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南桥', '南桥', 511);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南江', '南江', 512);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南江口', '南江口', 513);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南汤', '南汤', 514);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南河川', '南河川', 515);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南洼', '南洼', 516);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南湖东', '南湖东', 517);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南湾子', '南湾子', 518);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南翔北', '南翔北', 519);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南芬', '南芬', 520);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南芬北', '南芬', 521);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南观村', '南观村', 522);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南通', '南通', 523);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南部', '南部', 524);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南阳', '南阳', 525);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南阳寨', '南阳寨', 526);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南陈铺', '南陈铺', 527);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南陵', '南陵', 528);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南雄', '南雄', 529);
insert into Station (Station_Name, City_Name, Station_ID)
values ('南靖', '南靖', 530);
insert into Station (Station_Name, City_Name, Station_ID)
values ('博乐', '博乐', 531);
insert into Station (Station_Name, City_Name, Station_ID)
values ('博克图', '博克图', 532);
insert into Station (Station_Name, City_Name, Station_ID)
values ('博白', '博白', 533);
insert into Station (Station_Name, City_Name, Station_ID)
values ('博鳌', '博鳌', 534);
insert into Station (Station_Name, City_Name, Station_ID)
values ('卡伦', '卡伦', 535);
insert into Station (Station_Name, City_Name, Station_ID)
values ('卢龙', '卢龙', 536);
insert into Station (Station_Name, City_Name, Station_ID)
values ('卧里屯', '卧里屯', 537);
insert into Station (Station_Name, City_Name, Station_ID)
values ('卫星', '卫星', 538);
insert into Station (Station_Name, City_Name, Station_ID)
values ('卫辉', '卫辉', 539);
insert into Station (Station_Name, City_Name, Station_ID)
values ('即墨北', '即墨北', 540);
insert into Station (Station_Name, City_Name, Station_ID)
values ('原平', '原平', 541);
insert into Station (Station_Name, City_Name, Station_ID)
values ('原林', '原林', 542);
insert into Station (Station_Name, City_Name, Station_ID)
values ('厦门', '厦门', 543);
insert into Station (Station_Name, City_Name, Station_ID)
values ('厦门北', '厦门', 544);
insert into Station (Station_Name, City_Name, Station_ID)
values ('友好', '友好', 545);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双丰', '双丰', 546);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双凤驿', '双凤驿', 547);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双城北', '双城北', 548);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双城堡', '双城堡', 549);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双子河', '双子河', 550);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双峰北', '双峰北', 551);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双柳', '双柳', 552);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双河镇', '双河镇', 553);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双泡子', '双泡子', 554);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双流机场', '双流机场', 555);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双流西', '双流西', 556);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双牌', '双牌', 557);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双石桥', '双石桥', 558);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双辽', '双辽', 559);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双鸭山', '双鸭山', 560);
insert into Station (Station_Name, City_Name, Station_ID)
values ('双龙山', '双龙山', 561);
insert into Station (Station_Name, City_Name, Station_ID)
values ('发耳', '发耳', 562);
insert into Station (Station_Name, City_Name, Station_ID)
values ('口前', '口前', 563);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古东', '古东', 564);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古交', '古交', 565);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古城', '古城', 566);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古城子', '古城子', 567);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古城镇', '古城镇', 568);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古家沱', '古家沱', 569);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古浪', '古浪', 570);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古源', '古源', 571);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古田', '古田', 572);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古田会址', '古田会址', 573);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古田北', '古田', 574);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古莲', '古莲', 575);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古镇', '古镇', 576);
insert into Station (Station_Name, City_Name, Station_ID)
values ('古鲁满汗', '古鲁满汗', 577);
insert into Station (Station_Name, City_Name, Station_ID)
values ('句容西', '句容西', 578);
insert into Station (Station_Name, City_Name, Station_ID)
values ('台前', '台前', 579);
insert into Station (Station_Name, City_Name, Station_ID)
values ('台安', '台安', 580);
insert into Station (Station_Name, City_Name, Station_ID)
values ('台州', '台州', 581);
insert into Station (Station_Name, City_Name, Station_ID)
values ('史家铺', '史家铺', 582);
insert into Station (Station_Name, City_Name, Station_ID)
values ('叶城', '叶城', 583);
insert into Station (Station_Name, City_Name, Station_ID)
values ('叶柏寿', '叶柏寿', 584);
insert into Station (Station_Name, City_Name, Station_ID)
values ('司家岭', '司家岭', 585);
insert into Station (Station_Name, City_Name, Station_ID)
values ('合川', '合川', 586);
insert into Station (Station_Name, City_Name, Station_ID)
values ('合浦', '合浦', 587);
insert into Station (Station_Name, City_Name, Station_ID)
values ('合肥', '合肥', 588);
insert into Station (Station_Name, City_Name, Station_ID)
values ('合肥北城', '合肥', 589);
insert into Station (Station_Name, City_Name, Station_ID)
values ('合肥南', '合肥', 590);
insert into Station (Station_Name, City_Name, Station_ID)
values ('合阳北', '合阳北', 591);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吉安', '吉安', 592);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吉文', '吉文', 593);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吉新河', '吉新河', 594);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吉林', '吉林', 595);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吉舒', '吉舒', 596);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吉首', '吉首', 597);
insert into Station (Station_Name, City_Name, Station_ID)
values ('同心', '同心', 598);
insert into Station (Station_Name, City_Name, Station_ID)
values ('同江', '同江', 599);
insert into Station (Station_Name, City_Name, Station_ID)
values ('后寨', '后寨', 600);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吐列毛杜', '吐列毛杜', 601);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吐哈', '吐哈', 602);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吐鲁番', '吐鲁番', 603);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吐鲁番北', '吐鲁番', 604);
insert into Station (Station_Name, City_Name, Station_ID)
values ('向塘', '向塘', 605);
insert into Station (Station_Name, City_Name, Station_ID)
values ('向阳', '向阳', 606);
insert into Station (Station_Name, City_Name, Station_ID)
values ('向阳川', '向阳川', 607);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吕梁', '吕梁', 608);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吴堡', '吴堡', 609);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吴官田', '吴官田', 610);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吴家屯', '吴家屯', 611);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吴家川', '吴家川', 612);
insert into Station (Station_Name, City_Name, Station_ID)
values ('吴桥', '吴桥', 613);
insert into Station (Station_Name, City_Name, Station_ID)
values ('周口', '周口', 614);
insert into Station (Station_Name, City_Name, Station_ID)
values ('周家', '周家', 615);
insert into Station (Station_Name, City_Name, Station_ID)
values ('周家屯', '周家屯', 616);
insert into Station (Station_Name, City_Name, Station_ID)
values ('呼兰', '呼兰', 617);
insert into Station (Station_Name, City_Name, Station_ID)
values ('呼和浩特', '呼和浩特', 618);
insert into Station (Station_Name, City_Name, Station_ID)
values ('呼和浩特东', '呼和浩特', 619);
insert into Station (Station_Name, City_Name, Station_ID)
values ('呼鲁斯太', '呼鲁斯太', 620);
insert into Station (Station_Name, City_Name, Station_ID)
values ('和什托洛盖', '和什托洛盖', 621);
insert into Station (Station_Name, City_Name, Station_ID)
values ('和平', '和平', 622);
insert into Station (Station_Name, City_Name, Station_ID)
values ('和田', '和田', 623);
insert into Station (Station_Name, City_Name, Station_ID)
values ('和硕', '和硕', 624);
insert into Station (Station_Name, City_Name, Station_ID)
values ('和龙', '和龙', 625);
insert into Station (Station_Name, City_Name, Station_ID)
values ('咸宁', '咸宁', 626);
insert into Station (Station_Name, City_Name, Station_ID)
values ('咸宁东', '咸宁', 627);
insert into Station (Station_Name, City_Name, Station_ID)
values ('咸宁北', '咸宁', 628);
insert into Station (Station_Name, City_Name, Station_ID)
values ('咸宁南', '咸宁', 629);
insert into Station (Station_Name, City_Name, Station_ID)
values ('咸阳', '咸阳', 630);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈业胡同', '哈业胡同', 631);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈克', '哈克', 632);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈力图', '哈力图', 633);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈密', '哈密', 634);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈尔巴岭', '哈尔巴岭', 635);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈尔滨', '哈尔滨', 636);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈尔滨北', '哈尔滨', 637);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈尔滨西', '哈尔滨', 638);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈拉苏', '哈拉苏', 639);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈日努拉', '哈日努拉', 640);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈达', '哈达', 641);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哈达阳', '哈达阳', 642);
insert into Station (Station_Name, City_Name, Station_ID)
values ('哲里木', '哲里木', 643);
insert into Station (Station_Name, City_Name, Station_ID)
values ('唐家湾', '唐家湾', 644);
insert into Station (Station_Name, City_Name, Station_ID)
values ('唐山', '唐山', 645);
insert into Station (Station_Name, City_Name, Station_ID)
values ('唐山北', '唐山', 646);
insert into Station (Station_Name, City_Name, Station_ID)
values ('唐河', '唐河', 647);
insert into Station (Station_Name, City_Name, Station_ID)
values ('商丘', '商丘', 648);
insert into Station (Station_Name, City_Name, Station_ID)
values ('商丘南', '商丘', 649);
insert into Station (Station_Name, City_Name, Station_ID)
values ('商南', '商南', 650);
insert into Station (Station_Name, City_Name, Station_ID)
values ('商城', '商城', 651);
insert into Station (Station_Name, City_Name, Station_ID)
values ('商河', '商河', 652);
insert into Station (Station_Name, City_Name, Station_ID)
values ('商洛', '商洛', 653);
insert into Station (Station_Name, City_Name, Station_ID)
values ('商都', '商都', 654);
insert into Station (Station_Name, City_Name, Station_ID)
values ('喀什', '喀什', 655);
insert into Station (Station_Name, City_Name, Station_ID)
values ('喀喇其', '喀喇其', 656);
insert into Station (Station_Name, City_Name, Station_ID)
values ('喇嘛山', '喇嘛山', 657);
insert into Station (Station_Name, City_Name, Station_ID)
values ('喜德', '喜德', 658);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘉兴', '嘉兴', 659);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘉兴南', '嘉兴', 660);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘉善', '嘉善', 661);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘉善南', '嘉善', 662);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘉峪关', '嘉峪关', 663);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘉峪关南', '嘉峪关南', 664);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘉峰', '嘉峰', 665);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘉祥', '嘉祥', 666);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘎什吐', '嘎什吐', 667);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘎什甸子', '嘎什甸子', 668);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嘎拉德斯汰', '嘎拉德斯汰', 669);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四会', '四会', 670);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四分地', '四分地', 671);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四分滩', '四分滩', 672);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四合', '四合', 673);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四合永', '四合永', 674);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四家子', '四家子', 675);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四平', '四平', 676);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四平东', '四平', 677);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四方台', '四方台', 678);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四道湾', '四道湾', 679);
insert into Station (Station_Name, City_Name, Station_ID)
values ('四马架', '四马架', 680);
insert into Station (Station_Name, City_Name, Station_ID)
values ('团结', '团结', 681);
insert into Station (Station_Name, City_Name, Station_ID)
values ('园墩', '园墩', 682);
insert into Station (Station_Name, City_Name, Station_ID)
values ('固原', '固原', 683);
insert into Station (Station_Name, City_Name, Station_ID)
values ('固始', '固始', 684);
insert into Station (Station_Name, City_Name, Station_ID)
values ('固镇', '固镇', 685);
insert into Station (Station_Name, City_Name, Station_ID)
values ('图们', '图们', 686);
insert into Station (Station_Name, City_Name, Station_ID)
values ('图们北', '图们', 687);
insert into Station (Station_Name, City_Name, Station_ID)
values ('图强', '图强', 688);
insert into Station (Station_Name, City_Name, Station_ID)
values ('图里河', '图里河', 689);
insert into Station (Station_Name, City_Name, Station_ID)
values ('土们岭', '土们岭', 690);
insert into Station (Station_Name, City_Name, Station_ID)
values ('土地堂东', '土地堂东', 691);
insert into Station (Station_Name, City_Name, Station_ID)
values ('土桥子', '土桥子', 692);
insert into Station (Station_Name, City_Name, Station_ID)
values ('土溪', '土溪', 693);
insert into Station (Station_Name, City_Name, Station_ID)
values ('土牧尔台', '土牧尔台', 694);
insert into Station (Station_Name, City_Name, Station_ID)
values ('土贵乌拉', '土贵乌拉', 695);
insert into Station (Station_Name, City_Name, Station_ID)
values ('土门子', '土门子', 696);
insert into Station (Station_Name, City_Name, Station_ID)
values ('圣浪', '圣浪', 697);
insert into Station (Station_Name, City_Name, Station_ID)
values ('坝梁', '坝梁', 698);
insert into Station (Station_Name, City_Name, Station_ID)
values ('坡底下', '坡底下', 699);
insert into Station (Station_Name, City_Name, Station_ID)
values ('坪上', '坪上', 700);
insert into Station (Station_Name, City_Name, Station_ID)
values ('坪石', '坪石', 701);
insert into Station (Station_Name, City_Name, Station_ID)
values ('埃岱', '埃岱', 702);
insert into Station (Station_Name, City_Name, Station_ID)
values ('城固', '城固', 703);
insert into Station (Station_Name, City_Name, Station_ID)
values ('城子坦', '城子坦', 704);
insert into Station (Station_Name, City_Name, Station_ID)
values ('堡子湾', '堡子湾', 705);
insert into Station (Station_Name, City_Name, Station_ID)
values ('塔哈', '塔哈', 706);
insert into Station (Station_Name, City_Name, Station_ID)
values ('塔尔根', '塔尔根', 707);
insert into Station (Station_Name, City_Name, Station_ID)
values ('塔尔气', '塔尔气', 708);
insert into Station (Station_Name, City_Name, Station_ID)
values ('塔崖驿', '塔崖驿', 709);
insert into Station (Station_Name, City_Name, Station_ID)
values ('塔河', '塔河', 710);
insert into Station (Station_Name, City_Name, Station_ID)
values ('塔源', '塔源', 711);
insert into Station (Station_Name, City_Name, Station_ID)
values ('塘沽', '塘沽', 712);
insert into Station (Station_Name, City_Name, Station_ID)
values ('塘豹', '塘豹', 713);
insert into Station (Station_Name, City_Name, Station_ID)
values ('墨玉', '墨玉', 714);
insert into Station (Station_Name, City_Name, Station_ID)
values ('夏坝', '夏坝', 715);
insert into Station (Station_Name, City_Name, Station_ID)
values ('夏官营', '夏官营', 716);
insert into Station (Station_Name, City_Name, Station_ID)
values ('夏拉哈马', '夏拉哈马', 717);
insert into Station (Station_Name, City_Name, Station_ID)
values ('夏石', '夏石', 718);
insert into Station (Station_Name, City_Name, Station_ID)
values ('夏邑县', '夏邑县', 719);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大东', '大东', 720);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大乌苏', '大乌苏', 721);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大余', '大余', 722);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大关', '大关', 723);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大兴', '大兴', 724);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大兴沟', '大兴沟', 725);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大其拉哈', '大其拉哈', 726);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大冶北', '大冶北', 727);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大口钦', '大口钦', 728);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大同', '大同', 729);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大坝', '大坝', 730);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大埔', '大埔', 731);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大堡', '大堡', 732);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大孤山', '大孤山', 733);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大安北', '大安北', 734);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大官屯', '大官屯', 735);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大屯', '大屯', 736);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大山铺', '大山铺', 737);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大巴', '大巴', 738);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大平房', '大平房', 739);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大庆', '大庆', 740);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大庆东', '大庆', 741);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大庆西', '大庆', 742);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大徐屯', '大徐屯', 743);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大成', '大成', 744);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大战场', '大战场', 745);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大扬气', '大扬气', 746);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大旺', '大旺', 747);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大杖子', '大杖子', 748);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大杨树', '大杨树', 749);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大杨树东', '大杨树东', 750);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大板', '大板', 751);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大林', '大林', 752);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大武口', '大武口', 753);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大民屯', '大民屯', 754);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大河坝', '大河坝', 755);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大涧', '大涧', 756);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大湾子', '大湾子', 757);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大灰厂', '大灰厂', 758);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大理', '大理', 759);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大田边', '大田边', 760);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大盘石', '大盘石', 761);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大石头', '大石头', 762);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大石寨', '大石寨', 763);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大石桥', '大石桥', 764);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大磴沟', '大磴沟', 765);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大竹园', '大竹园', 766);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大红旗', '大红旗', 767);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大英东', '大英东', 768);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大苴', '大苴', 769);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大营', '大营', 770);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大营镇', '大营镇', 771);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大虎山', '大虎山', 772);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大西', '大西', 773);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大足', '大足', 774);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大足南', '大足', 775);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大辛庄', '大辛庄', 776);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大连', '大连', 777);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大连北', '大连', 778);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大通西', '大通西', 779);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大陆号', '大陆号', 780);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大雁', '大雁', 781);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大雅河', '大雅河', 782);
insert into Station (Station_Name, City_Name, Station_ID)
values ('大青沟', '大青沟', 783);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天义', '天义', 784);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天岗', '天岗', 785);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天柱山', '天柱山', 786);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天桥', '天桥', 787);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天桥岭', '天桥岭', 788);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天水', '天水', 789);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天津', '天津', 790);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天津南', '天津', 791);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天津西', '天津', 792);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天祝', '天祝', 793);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天西', '天西', 794);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天镇', '天镇', 795);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天门', '天门', 796);
insert into Station (Station_Name, City_Name, Station_ID)
values ('天门南', '天门南', 797);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太原', '太原', 798);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太原东', '太原', 799);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太原南', '太原', 800);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太姥山', '太姥山', 801);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太平川', '太平川', 802);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太平庄', '太平庄', 803);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太平镇', '太平镇', 804);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太湖', '太湖', 805);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太白', '太白', 806);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太谷', '太谷', 807);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太谷西', '太谷', 808);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太阳升', '太阳升', 809);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太阳山', '太阳山', 810);
insert into Station (Station_Name, City_Name, Station_ID)
values ('太阳沟', '太阳沟', 811);
insert into Station (Station_Name, City_Name, Station_ID)
values ('头道桥', '头道桥', 812);
insert into Station (Station_Name, City_Name, Station_ID)
values ('奇峰塔', '奇峰塔', 813);
insert into Station (Station_Name, City_Name, Station_ID)
values ('奈曼', '奈曼', 814);
insert into Station (Station_Name, City_Name, Station_ID)
values ('奉化', '奉化', 815);
insert into Station (Station_Name, City_Name, Station_ID)
values ('奎屯', '奎屯', 816);
insert into Station (Station_Name, City_Name, Station_ID)
values ('奎山', '奎山', 817);
insert into Station (Station_Name, City_Name, Station_ID)
values ('女儿河', '女儿河', 818);
insert into Station (Station_Name, City_Name, Station_ID)
values ('好鲁库', '好鲁库', 819);
insert into Station (Station_Name, City_Name, Station_ID)
values ('如东', '如东', 820);
insert into Station (Station_Name, City_Name, Station_ID)
values ('如皋', '如皋', 821);
insert into Station (Station_Name, City_Name, Station_ID)
values ('始兴', '始兴', 822);
insert into Station (Station_Name, City_Name, Station_ID)
values ('姑家堡', '姑家堡', 823);
insert into Station (Station_Name, City_Name, Station_ID)
values ('姚千户屯', '姚千户屯', 824);
insert into Station (Station_Name, City_Name, Station_ID)
values ('姚安', '姚安', 825);
insert into Station (Station_Name, City_Name, Station_ID)
values ('姚家', '姚家', 826);
insert into Station (Station_Name, City_Name, Station_ID)
values ('姜堰', '姜堰', 827);
insert into Station (Station_Name, City_Name, Station_ID)
values ('姜家', '姜家', 828);
insert into Station (Station_Name, City_Name, Station_ID)
values ('威宁', '威宁', 829);
insert into Station (Station_Name, City_Name, Station_ID)
values ('威岭', '威岭', 830);
insert into Station (Station_Name, City_Name, Station_ID)
values ('威海', '威海', 831);
insert into Station (Station_Name, City_Name, Station_ID)
values ('威箐', '威箐', 832);
insert into Station (Station_Name, City_Name, Station_ID)
values ('威舍', '威舍', 833);
insert into Station (Station_Name, City_Name, Station_ID)
values ('娄山关', '娄山关', 834);
insert into Station (Station_Name, City_Name, Station_ID)
values ('娄底', '娄底', 835);
insert into Station (Station_Name, City_Name, Station_ID)
values ('娄底南', '娄底', 836);
insert into Station (Station_Name, City_Name, Station_ID)
values ('娘娘庙', '娘娘庙', 837);
insert into Station (Station_Name, City_Name, Station_ID)
values ('娘子关', '娘子关', 838);
insert into Station (Station_Name, City_Name, Station_ID)
values ('婺源', '婺源', 839);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嫩江', '嫩江', 840);
insert into Station (Station_Name, City_Name, Station_ID)
values ('子洲', '子洲', 841);
insert into Station (Station_Name, City_Name, Station_ID)
values ('子长', '子长', 842);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孔垄', '孔垄', 843);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孔家沟', '孔家沟', 844);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孔庄', '孔庄', 845);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孔滩', '孔滩', 846);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孙吴', '孙吴', 847);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孙家', '孙家', 848);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孙镇', '孙镇', 849);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孝南', '孝南', 850);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孝感', '孝感', 851);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孝感北', '孝感', 852);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孝西', '孝西', 853);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孟家岗', '孟家岗', 854);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孟庄', '孟庄', 855);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孟津', '孟津', 856);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孤山', '孤山', 857);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孤山口', '孤山口', 858);
insert into Station (Station_Name, City_Name, Station_ID)
values ('孤山子', '孤山子', 859);
insert into Station (Station_Name, City_Name, Station_ID)
values ('学庄', '学庄', 860);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁东', '宁东', 861);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁东南', '宁东', 862);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁乡', '宁乡', 863);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁国', '宁国', 864);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁安', '宁安', 865);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁德', '宁德', 866);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁明', '宁明', 867);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁武', '宁武', 868);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁波', '宁波', 869);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁海', '宁海', 870);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宁陵县', '宁陵县', 871);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宇宙地', '宇宙地', 872);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安亭北', '安亭北', 873);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安仁', '安仁', 874);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安化', '安化', 875);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安口窑', '安口窑', 876);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安图', '安图', 877);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安图西', '安图', 878);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安塘', '安塘', 879);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安多', '安多', 880);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安定', '安定', 881);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安家', '安家', 882);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安富镇', '安富镇', 883);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安平', '安平', 884);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安广', '安广', 885);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安庆', '安庆', 886);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安庆沟', '安庆沟', 887);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安庆西', '安庆', 888);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安康', '安康', 889);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安德', '安德', 890);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安达', '安达', 891);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安阳', '安阳', 892);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安阳东', '安阳', 893);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安陆', '安陆', 894);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安顺', '安顺', 895);
insert into Station (Station_Name, City_Name, Station_ID)
values ('安龙', '安龙', 896);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宋', '宋', 897);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宋城路', '宋城路', 898);
insert into Station (Station_Name, City_Name, Station_ID)
values ('完工', '完工', 899);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宏庆', '宏庆', 900);
insert into Station (Station_Name, City_Name, Station_ID)
values ('官厅', '官厅', 901);
insert into Station (Station_Name, City_Name, Station_ID)
values ('官厅西', '官厅', 902);
insert into Station (Station_Name, City_Name, Station_ID)
values ('官字井', '官字井', 903);
insert into Station (Station_Name, City_Name, Station_ID)
values ('官高', '官高', 904);
insert into Station (Station_Name, City_Name, Station_ID)
values ('定南', '定南', 905);
insert into Station (Station_Name, City_Name, Station_ID)
values ('定州', '定州', 906);
insert into Station (Station_Name, City_Name, Station_ID)
values ('定州东', '定州', 907);
insert into Station (Station_Name, City_Name, Station_ID)
values ('定襄', '定襄', 908);
insert into Station (Station_Name, City_Name, Station_ID)
values ('定西', '定西', 909);
insert into Station (Station_Name, City_Name, Station_ID)
values ('定边', '定边', 910);
insert into Station (Station_Name, City_Name, Station_ID)
values ('定远', '定远', 911);
insert into Station (Station_Name, City_Name, Station_ID)
values ('定陶', '定陶', 912);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宜兴', '宜兴', 913);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宜城', '宜城', 914);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宜宾', '宜宾', 915);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宜宾南', '宜宾', 916);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宜州', '宜州', 917);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宜昌东', '宜昌东', 918);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宜春', '宜春', 919);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宜耐', '宜耐', 920);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宜良北', '宜良北', 921);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宝华山', '宝华山', 922);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宝拉格', '宝拉格', 923);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宝木吐', '宝木吐', 924);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宝林', '宝林', 925);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宝泉岭', '宝泉岭', 926);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宝清', '宝清', 927);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宝老山', '宝老山', 928);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宝鸡', '宝鸡', 929);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宝龙山', '宝龙山', 930);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宣化', '宣化', 931);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宣和', '宣和', 932);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宣城', '宣城', 933);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宣威', '宣威', 934);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宣家沟', '宣家沟', 935);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宣汉', '宣汉', 936);
insert into Station (Station_Name, City_Name, Station_ID)
values ('容县', '容县', 937);
insert into Station (Station_Name, City_Name, Station_ID)
values ('容桂', '容桂', 938);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宽甸', '宽甸', 939);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宾阳', '宾阳', 940);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宿州', '宿州', 941);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宿州东', '宿州', 942);
insert into Station (Station_Name, City_Name, Station_ID)
values ('宿松', '宿松', 943);
insert into Station (Station_Name, City_Name, Station_ID)
values ('密云北', '密云北', 944);
insert into Station (Station_Name, City_Name, Station_ID)
values ('密山', '密山', 945);
insert into Station (Station_Name, City_Name, Station_ID)
values ('密山西', '密山', 946);
insert into Station (Station_Name, City_Name, Station_ID)
values ('富县', '富县', 947);
insert into Station (Station_Name, City_Name, Station_ID)
values ('富县东', '富县', 948);
insert into Station (Station_Name, City_Name, Station_ID)
values ('富川', '富川', 949);
insert into Station (Station_Name, City_Name, Station_ID)
values ('富拉尔基', '富拉尔基', 950);
insert into Station (Station_Name, City_Name, Station_ID)
values ('富海', '富海', 951);
insert into Station (Station_Name, City_Name, Station_ID)
values ('富源', '富源', 952);
insert into Station (Station_Name, City_Name, Station_ID)
values ('富裕', '富裕', 953);
insert into Station (Station_Name, City_Name, Station_ID)
values ('富锦', '富锦', 954);
insert into Station (Station_Name, City_Name, Station_ID)
values ('寒岭', '寒岭', 955);
insert into Station (Station_Name, City_Name, Station_ID)
values ('寒葱沟', '寒葱沟', 956);
insert into Station (Station_Name, City_Name, Station_ID)
values ('察素齐', '察素齐', 957);
insert into Station (Station_Name, City_Name, Station_ID)
values ('对青山', '对青山', 958);
insert into Station (Station_Name, City_Name, Station_ID)
values ('寿阳', '寿阳', 959);
insert into Station (Station_Name, City_Name, Station_ID)
values ('将乐', '将乐', 960);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小东', '小东', 961);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小儿坪', '小儿坪', 962);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小关溪', '小关溪', 963);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小南海', '小南海', 964);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小哨', '小哨', 965);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小姑家', '小姑家', 966);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小宋', '小宋', 967);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小寺沟', '小寺沟', 968);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小山', '小山', 969);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小岭', '小岭', 970);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小市', '小市', 971);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小得江', '小得江', 972);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小扬气', '小扬气', 973);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小新街', '小新街', 974);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小月旧', '小月旧', 975);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小村', '小村', 976);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小榄', '小榄', 977);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小榆树', '小榆树', 978);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小池口', '小池口', 979);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小河沿', '小河沿', 980);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小河镇', '小河镇', 981);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小白', '小白', 982);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小西庄', '小西庄', 983);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小金口', '小金口', 984);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小雨谷', '小雨谷', 985);
insert into Station (Station_Name, City_Name, Station_ID)
values ('小黑山', '小黑山', 986);
insert into Station (Station_Name, City_Name, Station_ID)
values ('尔赛河', '尔赛河', 987);
insert into Station (Station_Name, City_Name, Station_ID)
values ('尖峰', '尖峰', 988);
insert into Station (Station_Name, City_Name, Station_ID)
values ('尚家', '尚家', 989);
insert into Station (Station_Name, City_Name, Station_ID)
values ('尚志', '尚志', 990);
insert into Station (Station_Name, City_Name, Station_ID)
values ('尤溪', '尤溪', 991);
insert into Station (Station_Name, City_Name, Station_ID)
values ('尹地', '尹地', 992);
insert into Station (Station_Name, City_Name, Station_ID)
values ('尼勒克', '尼勒克', 993);
insert into Station (Station_Name, City_Name, Station_ID)
values ('尼日', '尼日', 994);
insert into Station (Station_Name, City_Name, Station_ID)
values ('尼木', '尼木', 995);
insert into Station (Station_Name, City_Name, Station_ID)
values ('尼波', '尼波', 996);
insert into Station (Station_Name, City_Name, Station_ID)
values ('屏边', '屏边', 997);
insert into Station (Station_Name, City_Name, Station_ID)
values ('山丹', '山丹', 998);
insert into Station (Station_Name, City_Name, Station_ID)
values ('山坡东', '山坡东', 999);
insert into Station (Station_Name, City_Name, Station_ID)
values ('山城镇', '山城镇', 1000);
insert into Station (Station_Name, City_Name, Station_ID)
values ('山市', '山市', 1001);
insert into Station (Station_Name, City_Name, Station_ID)
values ('山河屯', '山河屯', 1002);
insert into Station (Station_Name, City_Name, Station_ID)
values ('山海关', '山海关', 1003);
insert into Station (Station_Name, City_Name, Station_ID)
values ('山湾子', '山湾子', 1004);
insert into Station (Station_Name, City_Name, Station_ID)
values ('山阴', '山阴', 1005);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岑溪', '岑溪', 1006);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岔江', '岔江', 1007);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岔河', '岔河', 1008);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岢岚', '岢岚', 1009);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岩会', '岩会', 1010);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岩山', '岩山', 1011);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岭北', '岭北', 1012);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岭南', '岭南', 1013);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岱岳', '岱岳', 1014);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岳家井', '岳家井', 1015);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岳池', '岳池', 1016);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岳阳', '岳阳', 1017);
insert into Station (Station_Name, City_Name, Station_ID)
values ('岳阳东', '岳阳', 1018);
insert into Station (Station_Name, City_Name, Station_ID)
values ('峡江', '峡江', 1019);
insert into Station (Station_Name, City_Name, Station_ID)
values ('峨眉', '峨眉', 1020);
insert into Station (Station_Name, City_Name, Station_ID)
values ('峨眉山', '峨眉山', 1021);
insert into Station (Station_Name, City_Name, Station_ID)
values ('峨边', '峨边', 1022);
insert into Station (Station_Name, City_Name, Station_ID)
values ('峰洞', '峰洞', 1023);
insert into Station (Station_Name, City_Name, Station_ID)
values ('峰高铺', '峰高铺', 1024);
insert into Station (Station_Name, City_Name, Station_ID)
values ('峻德', '峻德', 1025);
insert into Station (Station_Name, City_Name, Station_ID)
values ('崇信', '崇信', 1026);
insert into Station (Station_Name, City_Name, Station_ID)
values ('崇左', '崇左', 1027);
insert into Station (Station_Name, City_Name, Station_ID)
values ('崖州', '崖州', 1028);
insert into Station (Station_Name, City_Name, Station_ID)
values ('嵯岗', '嵯岗', 1029);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巢湖', '巢湖', 1030);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巢湖东', '巢湖', 1031);
insert into Station (Station_Name, City_Name, Station_ID)
values ('工农湖', '工农湖', 1032);
insert into Station (Station_Name, City_Name, Station_ID)
values ('左家', '左家', 1033);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巨宝', '巨宝', 1034);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巨野', '巨野', 1035);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巩义', '巩义', 1036);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巴东', '巴东', 1037);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巴中', '巴中', 1038);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巴山', '巴山', 1039);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巴彦郭勒', '巴彦郭勒', 1040);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巴彦高勒', '巴彦高勒', 1041);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巴林', '巴林', 1042);
insert into Station (Station_Name, City_Name, Station_ID)
values ('巴楚', '巴楚', 1043);
insert into Station (Station_Name, City_Name, Station_ID)
values ('布敦化', '布敦化', 1044);
insert into Station (Station_Name, City_Name, Station_ID)
values ('布海', '布海', 1045);
insert into Station (Station_Name, City_Name, Station_ID)
values ('师宗', '师宗', 1046);
insert into Station (Station_Name, City_Name, Station_ID)
values ('师庄', '师庄', 1047);
insert into Station (Station_Name, City_Name, Station_ID)
values ('带岭', '带岭', 1048);
insert into Station (Station_Name, City_Name, Station_ID)
values ('常州', '常州', 1049);
insert into Station (Station_Name, City_Name, Station_ID)
values ('常州北', '常州', 1050);
insert into Station (Station_Name, City_Name, Station_ID)
values ('常平', '常平', 1051);
insert into Station (Station_Name, City_Name, Station_ID)
values ('常平东', '常平', 1052);
insert into Station (Station_Name, City_Name, Station_ID)
values ('常庄', '常庄', 1053);
insert into Station (Station_Name, City_Name, Station_ID)
values ('常德', '常德', 1054);
insert into Station (Station_Name, City_Name, Station_ID)
values ('帽儿山', '帽儿山', 1055);
insert into Station (Station_Name, City_Name, Station_ID)
values ('干塘', '干塘', 1056);
insert into Station (Station_Name, City_Name, Station_ID)
values ('干溪沟', '干溪沟', 1057);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平关', '平关', 1058);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平凉', '平凉', 1059);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平凉南', '平凉', 1060);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平南南', '平南南', 1061);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平原', '平原', 1062);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平原堡', '平原堡', 1063);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平型关', '平型关', 1064);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平安', '平安', 1065);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平安驿', '平安驿', 1066);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平山', '平山', 1067);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平峪', '平峪', 1068);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平庄', '平庄', 1069);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平庄南', '平庄南', 1070);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平度', '平度', 1071);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平房', '平房', 1072);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平旺', '平旺', 1073);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平昌', '平昌', 1074);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平果', '平果', 1075);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平河口', '平河口', 1076);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平泉', '平泉', 1077);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平洋', '平洋', 1078);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平田', '平田', 1079);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平社', '平社', 1080);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平等', '平等', 1081);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平罗', '平罗', 1082);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平遥', '平遥', 1083);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平遥古城', '平遥古城', 1084);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平邑', '平邑', 1085);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平顶山', '平顶山', 1086);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平顶山西', '平顶山', 1087);
insert into Station (Station_Name, City_Name, Station_ID)
values ('平顶庙', '平顶庙', 1088);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广元', '广元', 1089);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广南卫', '广南卫', 1090);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广宁', '广宁', 1091);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广宁寺', '广宁寺', 1092);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广安', '广安', 1093);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广安南', '广安', 1094);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广州', '广州', 1095);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广州东', '广州', 1096);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广州北', '广州', 1097);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广州南', '广州', 1098);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广德', '广德', 1099);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广德号', '广德号', 1100);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广水', '广水', 1101);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广汉北', '广汉北', 1102);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广通北', '广通北', 1103);
insert into Station (Station_Name, City_Name, Station_ID)
values ('广顺场', '广顺场', 1104);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庄桥', '庄桥', 1105);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庄河北', '庄河北', 1106);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庆丰', '庆丰', 1107);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庆安', '庆安', 1108);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庆盛', '庆盛', 1109);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庆阳山', '庆阳山', 1110);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庐山', '庐山', 1111);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庐江', '庐江', 1112);
insert into Station (Station_Name, City_Name, Station_ID)
values ('库伦', '库伦', 1113);
insert into Station (Station_Name, City_Name, Station_ID)
values ('库尔勒', '库尔勒', 1114);
insert into Station (Station_Name, City_Name, Station_ID)
values ('库车', '库车', 1115);
insert into Station (Station_Name, City_Name, Station_ID)
values ('库都尔', '库都尔', 1116);
insert into Station (Station_Name, City_Name, Station_ID)
values ('应县', '应县', 1117);
insert into Station (Station_Name, City_Name, Station_ID)
values ('应城', '应城', 1118);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庙城', '庙城', 1119);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庙宫', '庙宫', 1120);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庙山', '庙山', 1121);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庙岭', '庙岭', 1122);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庙庄', '庙庄', 1123);
insert into Station (Station_Name, City_Name, Station_ID)
values ('庙阳', '庙阳', 1124);
insert into Station (Station_Name, City_Name, Station_ID)
values ('康城', '康城', 1125);
insert into Station (Station_Name, City_Name, Station_ID)
values ('康庄', '康庄', 1126);
insert into Station (Station_Name, City_Name, Station_ID)
values ('康金井', '康金井', 1127);
insert into Station (Station_Name, City_Name, Station_ID)
values ('廉江', '廉江', 1128);
insert into Station (Station_Name, City_Name, Station_ID)
values ('廊坊', '廊坊', 1129);
insert into Station (Station_Name, City_Name, Station_ID)
values ('廊坊北', '廊坊', 1130);
insert into Station (Station_Name, City_Name, Station_ID)
values ('延吉', '延吉', 1131);
insert into Station (Station_Name, City_Name, Station_ID)
values ('延吉西', '延吉', 1132);
insert into Station (Station_Name, City_Name, Station_ID)
values ('延安', '延安', 1133);
insert into Station (Station_Name, City_Name, Station_ID)
values ('建三江', '建三江', 1134);
insert into Station (Station_Name, City_Name, Station_ID)
values ('建始', '建始', 1135);
insert into Station (Station_Name, City_Name, Station_ID)
values ('建宁县北', '建宁县北', 1136);
insert into Station (Station_Name, City_Name, Station_ID)
values ('建昌', '建昌', 1137);
insert into Station (Station_Name, City_Name, Station_ID)
values ('建水', '建水', 1138);
insert into Station (Station_Name, City_Name, Station_ID)
values ('建湖', '建湖', 1139);
insert into Station (Station_Name, City_Name, Station_ID)
values ('建瓯', '建瓯', 1140);
insert into Station (Station_Name, City_Name, Station_ID)
values ('建瓯西', '建瓯', 1141);
insert into Station (Station_Name, City_Name, Station_ID)
values ('建设', '建设', 1142);
insert into Station (Station_Name, City_Name, Station_ID)
values ('建阳', '建阳', 1143);
insert into Station (Station_Name, City_Name, Station_ID)
values ('开原', '开原', 1144);
insert into Station (Station_Name, City_Name, Station_ID)
values ('开原西', '开原', 1145);
insert into Station (Station_Name, City_Name, Station_ID)
values ('开封', '开封', 1146);
insert into Station (Station_Name, City_Name, Station_ID)
values ('开江', '开江', 1147);
insert into Station (Station_Name, City_Name, Station_ID)
values ('开通', '开通', 1148);
insert into Station (Station_Name, City_Name, Station_ID)
values ('开道', '开道', 1149);
insert into Station (Station_Name, City_Name, Station_ID)
values ('开阳', '开阳', 1150);
insert into Station (Station_Name, City_Name, Station_ID)
values ('开鲁', '开鲁', 1151);
insert into Station (Station_Name, City_Name, Station_ID)
values ('弋江', '弋江', 1152);
insert into Station (Station_Name, City_Name, Station_ID)
values ('弋阳', '弋阳', 1153);
insert into Station (Station_Name, City_Name, Station_ID)
values ('弓棚子', '弓棚子', 1154);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张三营', '张三营', 1155);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张兰', '张兰', 1156);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张台子', '张台子', 1157);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张家口南', '张家口南', 1158);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张家界', '张家界', 1159);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张掖', '张掖', 1160);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张掖西', '张掖', 1161);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张桥', '张桥', 1162);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张百湾', '张百湾', 1163);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张维屯', '张维屯', 1164);
insert into Station (Station_Name, City_Name, Station_ID)
values ('张辛', '张辛', 1165);
insert into Station (Station_Name, City_Name, Station_ID)
values ('弥渡', '弥渡', 1166);
insert into Station (Station_Name, City_Name, Station_ID)
values ('弯易', '弯易', 1167);
insert into Station (Station_Name, City_Name, Station_ID)
values ('弯道', '弯道', 1168);
insert into Station (Station_Name, City_Name, Station_ID)
values ('弯郎', '弯郎', 1169);
insert into Station (Station_Name, City_Name, Station_ID)
values ('归流河', '归流河', 1170);
insert into Station (Station_Name, City_Name, Station_ID)
values ('当涂东', '当涂东', 1171);
insert into Station (Station_Name, City_Name, Station_ID)
values ('当阳', '当阳', 1172);
insert into Station (Station_Name, City_Name, Station_ID)
values ('当雄', '当雄', 1173);
insert into Station (Station_Name, City_Name, Station_ID)
values ('彝良', '彝良', 1174);
insert into Station (Station_Name, City_Name, Station_ID)
values ('彝良南', '彝良', 1175);
insert into Station (Station_Name, City_Name, Station_ID)
values ('彭山北', '彭山北', 1176);
insert into Station (Station_Name, City_Name, Station_ID)
values ('彭州', '彭州', 1177);
insert into Station (Station_Name, City_Name, Station_ID)
values ('彭水', '彭水', 1178);
insert into Station (Station_Name, City_Name, Station_ID)
values ('彭泽', '彭泽', 1179);
insert into Station (Station_Name, City_Name, Station_ID)
values ('彭阳', '彭阳', 1180);
insert into Station (Station_Name, City_Name, Station_ID)
values ('彰武', '彰武', 1181);
insert into Station (Station_Name, City_Name, Station_ID)
values ('影壁山', '影壁山', 1182);
insert into Station (Station_Name, City_Name, Station_ID)
values ('待王', '待王', 1183);
insert into Station (Station_Name, City_Name, Station_ID)
values ('徐家', '徐家', 1184);
insert into Station (Station_Name, City_Name, Station_ID)
values ('徐州', '徐州', 1185);
insert into Station (Station_Name, City_Name, Station_ID)
values ('徐州东', '徐州', 1186);
insert into Station (Station_Name, City_Name, Station_ID)
values ('徐水', '徐水', 1187);
insert into Station (Station_Name, City_Name, Station_ID)
values ('徐闻', '徐闻', 1188);
insert into Station (Station_Name, City_Name, Station_ID)
values ('得耳布尔', '得耳布尔', 1189);
insert into Station (Station_Name, City_Name, Station_ID)
values ('徘徊北', '徘徊北', 1190);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德令哈', '德令哈', 1191);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德伯斯', '德伯斯', 1192);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德保', '德保', 1193);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德兴', '德兴', 1194);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德安', '德安', 1195);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德州', '德州', 1196);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德州东', '德州', 1197);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德惠', '德惠', 1198);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德惠西', '德惠', 1199);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德日斯图', '德日斯图', 1200);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德昌', '德昌', 1201);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德清', '德清', 1202);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德清西', '德清', 1203);
insert into Station (Station_Name, City_Name, Station_ID)
values ('德阳', '德阳', 1204);
insert into Station (Station_Name, City_Name, Station_ID)
values ('徽县', '徽县', 1205);
insert into Station (Station_Name, City_Name, Station_ID)
values ('忻州', '忻州', 1206);
insert into Station (Station_Name, City_Name, Station_ID)
values ('怀仁', '怀仁', 1207);
insert into Station (Station_Name, City_Name, Station_ID)
values ('怀仁东', '怀仁', 1208);
insert into Station (Station_Name, City_Name, Station_ID)
values ('怀化', '怀化', 1209);
insert into Station (Station_Name, City_Name, Station_ID)
values ('怀化南', '怀化', 1210);
insert into Station (Station_Name, City_Name, Station_ID)
values ('怀柔', '怀柔', 1211);
insert into Station (Station_Name, City_Name, Station_ID)
values ('怀柔北', '怀柔', 1212);
insert into Station (Station_Name, City_Name, Station_ID)
values ('怀集', '怀集', 1213);
insert into Station (Station_Name, City_Name, Station_ID)
values ('恒地营', '恒地营', 1214);
insert into Station (Station_Name, City_Name, Station_ID)
values ('恩施', '恩施', 1215);
insert into Station (Station_Name, City_Name, Station_ID)
values ('恭城', '恭城', 1216);
insert into Station (Station_Name, City_Name, Station_ID)
values ('息县', '息县', 1217);
insert into Station (Station_Name, City_Name, Station_ID)
values ('息烽', '息烽', 1218);
insert into Station (Station_Name, City_Name, Station_ID)
values ('悬钟', '悬钟', 1219);
insert into Station (Station_Name, City_Name, Station_ID)
values ('惠东', '惠东', 1220);
insert into Station (Station_Name, City_Name, Station_ID)
values ('惠农', '惠农', 1221);
insert into Station (Station_Name, City_Name, Station_ID)
values ('惠安', '惠安', 1222);
insert into Station (Station_Name, City_Name, Station_ID)
values ('惠山', '惠山', 1223);
insert into Station (Station_Name, City_Name, Station_ID)
values ('惠州', '惠州', 1224);
insert into Station (Station_Name, City_Name, Station_ID)
values ('惠州南', '惠州', 1225);
insert into Station (Station_Name, City_Name, Station_ID)
values ('惠州西', '惠州', 1226);
insert into Station (Station_Name, City_Name, Station_ID)
values ('惠环', '惠环', 1227);
insert into Station (Station_Name, City_Name, Station_ID)
values ('慈利', '慈利', 1228);
insert into Station (Station_Name, City_Name, Station_ID)
values ('成吉思汗', '成吉思汗', 1229);
insert into Station (Station_Name, City_Name, Station_ID)
values ('成都', '成都', 1230);
insert into Station (Station_Name, City_Name, Station_ID)
values ('成都东', '成都', 1231);
insert into Station (Station_Name, City_Name, Station_ID)
values ('成都南', '成都', 1232);
insert into Station (Station_Name, City_Name, Station_ID)
values ('成高子', '成高子', 1233);
insert into Station (Station_Name, City_Name, Station_ID)
values ('戚墅堰', '戚墅堰', 1234);
insert into Station (Station_Name, City_Name, Station_ID)
values ('扎兰屯', '扎兰屯', 1235);
insert into Station (Station_Name, City_Name, Station_ID)
values ('扎罗木得', '扎罗木得', 1236);
insert into Station (Station_Name, City_Name, Station_ID)
values ('扎赉诺尔', '扎赉诺尔', 1237);
insert into Station (Station_Name, City_Name, Station_ID)
values ('扎赉诺尔西', '扎赉诺尔', 1238);
insert into Station (Station_Name, City_Name, Station_ID)
values ('扎音河', '扎音河', 1239);
insert into Station (Station_Name, City_Name, Station_ID)
values ('扎鲁特', '扎鲁特', 1240);
insert into Station (Station_Name, City_Name, Station_ID)
values ('打柴沟', '打柴沟', 1241);
insert into Station (Station_Name, City_Name, Station_ID)
values ('打羊', '打羊', 1242);
insert into Station (Station_Name, City_Name, Station_ID)
values ('扬州', '扬州', 1243);
insert into Station (Station_Name, City_Name, Station_ID)
values ('扶余', '扶余', 1244);
insert into Station (Station_Name, City_Name, Station_ID)
values ('扶余北', '扶余', 1245);
insert into Station (Station_Name, City_Name, Station_ID)
values ('扶绥', '扶绥', 1246);
insert into Station (Station_Name, City_Name, Station_ID)
values ('承德', '承德', 1247);
insert into Station (Station_Name, City_Name, Station_ID)
values ('承德东', '承德', 1248);
insert into Station (Station_Name, City_Name, Station_ID)
values ('抚宁', '抚宁', 1249);
insert into Station (Station_Name, City_Name, Station_ID)
values ('抚州', '抚州', 1250);
insert into Station (Station_Name, City_Name, Station_ID)
values ('抚州东', '抚州', 1251);
insert into Station (Station_Name, City_Name, Station_ID)
values ('抚松', '抚松', 1252);
insert into Station (Station_Name, City_Name, Station_ID)
values ('抚远', '抚远', 1253);
insert into Station (Station_Name, City_Name, Station_ID)
values ('抚顺', '抚顺', 1254);
insert into Station (Station_Name, City_Name, Station_ID)
values ('抚顺北', '抚顺', 1255);
insert into Station (Station_Name, City_Name, Station_ID)
values ('拉古', '拉古', 1256);
insert into Station (Station_Name, City_Name, Station_ID)
values ('拉哈', '拉哈', 1257);
insert into Station (Station_Name, City_Name, Station_ID)
values ('拉林', '拉林', 1258);
insert into Station (Station_Name, City_Name, Station_ID)
values ('拉白', '拉白', 1259);
insert into Station (Station_Name, City_Name, Station_ID)
values ('拉萨', '拉萨', 1260);
insert into Station (Station_Name, City_Name, Station_ID)
values ('拉鲊', '拉鲊', 1261);
insert into Station (Station_Name, City_Name, Station_ID)
values ('招柏', '招柏', 1262);
insert into Station (Station_Name, City_Name, Station_ID)
values ('换新天', '换新天', 1263);
insert into Station (Station_Name, City_Name, Station_ID)
values ('揭阳', '揭阳', 1264);
insert into Station (Station_Name, City_Name, Station_ID)
values ('攀枝花', '攀枝花', 1265);
insert into Station (Station_Name, City_Name, Station_ID)
values ('攸县南', '攸县南', 1266);
insert into Station (Station_Name, City_Name, Station_ID)
values ('敖力布告', '敖力布告', 1267);
insert into Station (Station_Name, City_Name, Station_ID)
values ('敖头', '敖头', 1268);
insert into Station (Station_Name, City_Name, Station_ID)
values ('敖来', '敖来', 1269);
insert into Station (Station_Name, City_Name, Station_ID)
values ('敖汉', '敖汉', 1270);
insert into Station (Station_Name, City_Name, Station_ID)
values ('敦化', '敦化', 1271);
insert into Station (Station_Name, City_Name, Station_ID)
values ('敦煌', '敦煌', 1272);
insert into Station (Station_Name, City_Name, Station_ID)
values ('敬梓场', '敬梓场', 1273);
insert into Station (Station_Name, City_Name, Station_ID)
values ('文地', '文地', 1274);
insert into Station (Station_Name, City_Name, Station_ID)
values ('文昌', '文昌', 1275);
insert into Station (Station_Name, City_Name, Station_ID)
values ('文水', '文水', 1276);
insert into Station (Station_Name, City_Name, Station_ID)
values ('文登', '文登', 1277);
insert into Station (Station_Name, City_Name, Station_ID)
values ('文登东', '文登', 1278);
insert into Station (Station_Name, City_Name, Station_ID)
values ('斗沟子', '斗沟子', 1279);
insert into Station (Station_Name, City_Name, Station_ID)
values ('斜河涧', '斜河涧', 1280);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新乡', '新乡', 1281);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新乡东', '新乡', 1282);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新会', '新会', 1283);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新余', '新余', 1284);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新余北', '新余', 1285);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新凉', '新凉', 1286);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新化', '新化', 1287);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新化南', '新化', 1288);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新华', '新华', 1289);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新华屯', '新华屯', 1290);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新县', '新县', 1291);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新友谊', '新友谊', 1292);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新和', '新和', 1293);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新固镇', '新固镇', 1294);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新场', '新场', 1295);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新坪田', '新坪田', 1296);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新天', '新天', 1297);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新安', '新安', 1298);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新安县', '新安县', 1299);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新安庄', '新安庄', 1300);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新寒岭', '新寒岭', 1301);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新帐房', '新帐房', 1302);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新干', '新干', 1303);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新平坝', '新平坝', 1304);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新开', '新开', 1305);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新彦', '新彦', 1306);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新晃', '新晃', 1307);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新晃西', '新晃', 1308);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新李', '新李', 1309);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新杖子', '新杖子', 1310);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新松浦', '新松浦', 1311);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新林', '新林', 1312);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新民', '新民', 1313);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新江', '新江', 1314);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新沂', '新沂', 1315);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新津', '新津', 1316);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新津南', '新津', 1317);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新窝铺', '新窝铺', 1318);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新立屯', '新立屯', 1319);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新立镇', '新立镇', 1320);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新绛', '新绛', 1321);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新绰源', '新绰源', 1322);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新肇', '新肇', 1323);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新邱', '新邱', 1324);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新郑机场', '新郑机场', 1325);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新都东', '新都东', 1326);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新阳镇', '新阳镇', 1327);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新青', '新青', 1328);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新香坊', '新香坊', 1329);
insert into Station (Station_Name, City_Name, Station_ID)
values ('新高峰', '新高峰', 1330);
insert into Station (Station_Name, City_Name, Station_ID)
values ('施家嘴', '施家嘴', 1331);
insert into Station (Station_Name, City_Name, Station_ID)
values ('施秉', '施秉', 1332);
insert into Station (Station_Name, City_Name, Station_ID)
values ('旌德', '旌德', 1333);
insert into Station (Station_Name, City_Name, Station_ID)
values ('旗下营', '旗下营', 1334);
insert into Station (Station_Name, City_Name, Station_ID)
values ('无为', '无为', 1335);
insert into Station (Station_Name, City_Name, Station_ID)
values ('无锡', '无锡', 1336);
insert into Station (Station_Name, City_Name, Station_ID)
values ('无锡东', '无锡', 1337);
insert into Station (Station_Name, City_Name, Station_ID)
values ('无锡新区', '无锡新区', 1338);
insert into Station (Station_Name, City_Name, Station_ID)
values ('日喀则', '日喀则', 1339);
insert into Station (Station_Name, City_Name, Station_ID)
values ('日照', '日照', 1340);
insert into Station (Station_Name, City_Name, Station_ID)
values ('旧庄窝', '旧庄窝', 1341);
insert into Station (Station_Name, City_Name, Station_ID)
values ('旬阳', '旬阳', 1342);
insert into Station (Station_Name, City_Name, Station_ID)
values ('旬阳北', '旬阳', 1343);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昂乃', '昂乃', 1344);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昂昂溪', '昂昂溪', 1345);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昆山', '昆山', 1346);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昆山南', '昆山', 1347);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昆明', '昆明', 1348);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昆独仑召', '昆独仑召', 1349);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昆都庙', '昆都庙', 1350);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昆阳', '昆阳', 1351);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昌乐', '昌乐', 1352);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昌图', '昌图', 1353);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昌图西', '昌图', 1354);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昌平', '昌平', 1355);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昌黎', '昌黎', 1356);
insert into Station (Station_Name, City_Name, Station_ID)
values ('明光', '明光', 1357);
insert into Station (Station_Name, City_Name, Station_ID)
values ('明城', '明城', 1358);
insert into Station (Station_Name, City_Name, Station_ID)
values ('明安', '明安', 1359);
insert into Station (Station_Name, City_Name, Station_ID)
values ('明水河', '明水河', 1360);
insert into Station (Station_Name, City_Name, Station_ID)
values ('明港东', '明港东', 1361);
insert into Station (Station_Name, City_Name, Station_ID)
values ('明珠', '明珠', 1362);
insert into Station (Station_Name, City_Name, Station_ID)
values ('星朗', '星朗', 1363);
insert into Station (Station_Name, City_Name, Station_ID)
values ('星耀', '星耀', 1364);
insert into Station (Station_Name, City_Name, Station_ID)
values ('春亭阁', '春亭阁', 1365);
insert into Station (Station_Name, City_Name, Station_ID)
values ('春阳', '春阳', 1366);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昭通', '昭通', 1367);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昭通北', '昭通', 1368);
insert into Station (Station_Name, City_Name, Station_ID)
values ('昭通南', '昭通', 1369);
insert into Station (Station_Name, City_Name, Station_ID)
values ('晋中', '晋中', 1370);
insert into Station (Station_Name, City_Name, Station_ID)
values ('晋城', '晋城', 1371);
insert into Station (Station_Name, City_Name, Station_ID)
values ('晋城北', '晋城', 1372);
insert into Station (Station_Name, City_Name, Station_ID)
values ('晋州', '晋州', 1373);
insert into Station (Station_Name, City_Name, Station_ID)
values ('晋江', '晋江', 1374);
insert into Station (Station_Name, City_Name, Station_ID)
values ('晏城', '晏城', 1375);
insert into Station (Station_Name, City_Name, Station_ID)
values ('晨明', '晨明', 1376);
insert into Station (Station_Name, City_Name, Station_ID)
values ('普兰店', '普兰店', 1377);
insert into Station (Station_Name, City_Name, Station_ID)
values ('普宁', '普宁', 1378);
insert into Station (Station_Name, City_Name, Station_ID)
values ('普安', '普安', 1379);
insert into Station (Station_Name, City_Name, Station_ID)
values ('普定', '普定', 1380);
insert into Station (Station_Name, City_Name, Station_ID)
values ('普洱渡', '普洱渡', 1381);
insert into Station (Station_Name, City_Name, Station_ID)
values ('普湾', '普湾', 1382);
insert into Station (Station_Name, City_Name, Station_ID)
values ('普雄', '普雄', 1383);
insert into Station (Station_Name, City_Name, Station_ID)
values ('景德镇', '景德镇', 1384);
insert into Station (Station_Name, City_Name, Station_ID)
values ('景泰', '景泰', 1385);
insert into Station (Station_Name, City_Name, Station_ID)
values ('暖泉', '暖泉', 1386);
insert into Station (Station_Name, City_Name, Station_ID)
values ('曲家店', '曲家店', 1387);
insert into Station (Station_Name, City_Name, Station_ID)
values ('曲水县', '曲水县', 1388);
insert into Station (Station_Name, City_Name, Station_ID)
values ('曲江', '曲江', 1389);
insert into Station (Station_Name, City_Name, Station_ID)
values ('曲阜', '曲阜', 1390);
insert into Station (Station_Name, City_Name, Station_ID)
values ('曲阜东', '曲阜', 1391);
insert into Station (Station_Name, City_Name, Station_ID)
values ('曲靖', '曲靖', 1392);
insert into Station (Station_Name, City_Name, Station_ID)
values ('曹县', '曹县', 1393);
insert into Station (Station_Name, City_Name, Station_ID)
values ('曹家营子', '曹家营子', 1394);
insert into Station (Station_Name, City_Name, Station_ID)
values ('曾家坪子', '曾家坪子', 1395);
insert into Station (Station_Name, City_Name, Station_ID)
values ('月亮田', '月亮田', 1396);
insert into Station (Station_Name, City_Name, Station_ID)
values ('月华', '月华', 1397);
insert into Station (Station_Name, City_Name, Station_ID)
values ('月山', '月山', 1398);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朔州', '朔州', 1399);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朗乡', '朗乡', 1400);
insert into Station (Station_Name, City_Name, Station_ID)
values ('望江', '望江', 1401);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朝中', '朝中', 1402);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朝天', '朝天', 1403);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朝格温多尔', '朝格温多尔', 1404);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朝阳', '朝阳', 1405);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朝阳地', '朝阳地', 1406);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朝阳川', '朝阳川', 1407);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朝阳村', '朝阳村', 1408);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朝阳镇', '朝阳镇', 1409);
insert into Station (Station_Name, City_Name, Station_ID)
values ('木竹河', '木竹河', 1410);
insert into Station (Station_Name, City_Name, Station_ID)
values ('木里图', '木里图', 1411);
insert into Station (Station_Name, City_Name, Station_ID)
values ('本溪', '本溪', 1412);
insert into Station (Station_Name, City_Name, Station_ID)
values ('本溪新城', '本溪新城', 1413);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朱家沟', '朱家沟', 1414);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朱家窑', '朱家窑', 1415);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朱日和', '朱日和', 1416);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朱杨溪', '朱杨溪', 1417);
insert into Station (Station_Name, City_Name, Station_ID)
values ('朱石寨', '朱石寨', 1418);
insert into Station (Station_Name, City_Name, Station_ID)
values ('李家', '李家', 1419);
insert into Station (Station_Name, City_Name, Station_ID)
values ('李家坪', '李家坪', 1420);
insert into Station (Station_Name, City_Name, Station_ID)
values ('李市镇', '李市镇', 1421);
insert into Station (Station_Name, City_Name, Station_ID)
values ('李旺', '李旺', 1422);
insert into Station (Station_Name, City_Name, Station_ID)
values ('李石寨', '李石寨', 1423);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杏树', '杏树', 1424);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杏树屯', '杏树屯', 1425);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杜家', '杜家', 1426);
insert into Station (Station_Name, City_Name, Station_ID)
values ('来宾', '来宾', 1427);
insert into Station (Station_Name, City_Name, Station_ID)
values ('来宾北', '来宾', 1428);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨家店', '杨家店', 1429);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨家营', '杨家营', 1430);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨岗', '杨岗', 1431);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨木', '杨木', 1432);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨村', '杨村', 1433);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨杖子', '杨杖子', 1434);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨林', '杨林', 1435);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨柳青', '杨柳青', 1436);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨树岭', '杨树岭', 1437);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨树湾', '杨树湾', 1438);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨漩', '杨漩', 1439);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杨陵', '杨陵', 1440);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杭州', '杭州', 1441);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杭州东', '杭州', 1442);
insert into Station (Station_Name, City_Name, Station_ID)
values ('杭锦旗', '杭锦旗', 1443);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松原', '松原', 1444);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松原北', '松原', 1445);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松坎', '松坎', 1446);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松坝', '松坝', 1447);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松树', '松树', 1448);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松树台', '松树台', 1449);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松树林', '松树林', 1450);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松树镇', '松树镇', 1451);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松桃', '松桃', 1452);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松江', '松江', 1453);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松江南', '松江', 1454);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松江河', '松江河', 1455);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松江镇', '松江镇', 1456);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松河', '松河', 1457);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松滋', '松滋', 1458);
insert into Station (Station_Name, City_Name, Station_ID)
values ('松青', '松青', 1459);
insert into Station (Station_Name, City_Name, Station_ID)
values ('板城', '板城', 1460);
insert into Station (Station_Name, City_Name, Station_ID)
values ('板石河', '板石河', 1461);
insert into Station (Station_Name, City_Name, Station_ID)
values ('枕头峰', '枕头峰', 1462);
insert into Station (Station_Name, City_Name, Station_ID)
values ('林东', '林东', 1463);
insert into Station (Station_Name, City_Name, Station_ID)
values ('林口', '林口', 1464);
insert into Station (Station_Name, City_Name, Station_ID)
values ('林家台', '林家台', 1465);
insert into Station (Station_Name, City_Name, Station_ID)
values ('林海', '林海', 1466);
insert into Station (Station_Name, City_Name, Station_ID)
values ('林源', '林源', 1467);
insert into Station (Station_Name, City_Name, Station_ID)
values ('林盛堡', '林盛堡', 1468);
insert into Station (Station_Name, City_Name, Station_ID)
values ('林西', '林西', 1469);
insert into Station (Station_Name, City_Name, Station_ID)
values ('果松', '果松', 1470);
insert into Station (Station_Name, City_Name, Station_ID)
values ('枝城', '枝城', 1471);
insert into Station (Station_Name, City_Name, Station_ID)
values ('枝江北', '枝江北', 1472);
insert into Station (Station_Name, City_Name, Station_ID)
values ('枣子林', '枣子林', 1473);
insert into Station (Station_Name, City_Name, Station_ID)
values ('枣庄', '枣庄', 1474);
insert into Station (Station_Name, City_Name, Station_ID)
values ('枣庄东', '枣庄', 1475);
insert into Station (Station_Name, City_Name, Station_ID)
values ('枣庄西', '枣庄', 1476);
insert into Station (Station_Name, City_Name, Station_ID)
values ('枣强', '枣强', 1477);
insert into Station (Station_Name, City_Name, Station_ID)
values ('枣林', '枣林', 1478);
insert into Station (Station_Name, City_Name, Station_ID)
values ('枣阳', '枣阳', 1479);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柏村', '柏村', 1480);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柏林', '柏林', 1481);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柏果', '柏果', 1482);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柞水', '柞水', 1483);
insert into Station (Station_Name, City_Name, Station_ID)
values ('查布嘎', '查布嘎', 1484);
insert into Station (Station_Name, City_Name, Station_ID)
values ('查干哈达', '查干哈达', 1485);
insert into Station (Station_Name, City_Name, Station_ID)
values ('查干特格', '查干特格', 1486);
insert into Station (Station_Name, City_Name, Station_ID)
values ('查干芒和', '查干芒和', 1487);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柯坪', '柯坪', 1488);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柯柯', '柯柯', 1489);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳园', '柳园', 1490);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳园南', '柳园', 1491);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳家庄', '柳家庄', 1492);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳州', '柳州', 1493);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳林南', '柳林南', 1494);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳树', '柳树', 1495);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳树屯', '柳树屯', 1496);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳毛', '柳毛', 1497);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳毛沟', '柳毛沟', 1498);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳沟', '柳沟', 1499);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柳河', '柳河', 1500);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柴沟堡', '柴沟堡', 1501);
insert into Station (Station_Name, City_Name, Station_ID)
values ('柴河', '柴河', 1502);
insert into Station (Station_Name, City_Name, Station_ID)
values ('栟茶', '栟茶', 1503);
insert into Station (Station_Name, City_Name, Station_ID)
values ('株洲', '株洲', 1504);
insert into Station (Station_Name, City_Name, Station_ID)
values ('株洲西', '株洲', 1505);
insert into Station (Station_Name, City_Name, Station_ID)
values ('核桃园', '核桃园', 1506);
insert into Station (Station_Name, City_Name, Station_ID)
values ('根河', '根河', 1507);
insert into Station (Station_Name, City_Name, Station_ID)
values ('格尔木', '格尔木', 1508);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桂平', '桂平', 1509);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桂林', '桂林', 1510);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桂林北', '桂林', 1511);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桂林西', '桂林', 1512);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桃园', '桃园', 1513);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桃山', '桃山', 1514);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桃村', '桃村', 1515);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桃村北', '桃村', 1516);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桐乡', '桐乡', 1517);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桐城', '桐城', 1518);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桐子林', '桐子林', 1519);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桐木寨', '桐木寨', 1520);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桐柏', '桐柏', 1521);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桐梓', '桐梓', 1522);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桑根达来', '桑根达来', 1523);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桓龙湖', '桓龙湖', 1524);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桥北', '桥北', 1525);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桥头', '桥头', 1526);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桥湾', '桥湾', 1527);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桦南', '桦南', 1528);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桦林', '桦林', 1529);
insert into Station (Station_Name, City_Name, Station_ID)
values ('桦皮厂', '桦皮厂', 1530);
insert into Station (Station_Name, City_Name, Station_ID)
values ('梁山', '梁山', 1531);
insert into Station (Station_Name, City_Name, Station_ID)
values ('梁平', '梁平', 1532);
insert into Station (Station_Name, City_Name, Station_ID)
values ('梁底下', '梁底下', 1533);
insert into Station (Station_Name, City_Name, Station_ID)
values ('梅州', '梅州', 1534);
insert into Station (Station_Name, City_Name, Station_ID)
values ('梅河口', '梅河口', 1535);
insert into Station (Station_Name, City_Name, Station_ID)
values ('梧州', '梧州', 1536);
insert into Station (Station_Name, City_Name, Station_ID)
values ('梧州南', '梧州', 1537);
insert into Station (Station_Name, City_Name, Station_ID)
values ('梨树镇', '梨树镇', 1538);
insert into Station (Station_Name, City_Name, Station_ID)
values ('棋子湾', '棋子湾', 1539);
insert into Station (Station_Name, City_Name, Station_ID)
values ('棋盘', '棋盘', 1540);
insert into Station (Station_Name, City_Name, Station_ID)
values ('楚山', '楚山', 1541);
insert into Station (Station_Name, City_Name, Station_ID)
values ('楚雄', '楚雄', 1542);
insert into Station (Station_Name, City_Name, Station_ID)
values ('楚鲁图', '楚鲁图', 1543);
insert into Station (Station_Name, City_Name, Station_ID)
values ('榆林', '榆林', 1544);
insert into Station (Station_Name, City_Name, Station_ID)
values ('榆树', '榆树', 1545);
insert into Station (Station_Name, City_Name, Station_ID)
values ('榆树屯', '榆树屯', 1546);
insert into Station (Station_Name, City_Name, Station_ID)
values ('榆树川', '榆树川', 1547);
insert into Station (Station_Name, City_Name, Station_ID)
values ('榆树沟', '榆树沟', 1548);
insert into Station (Station_Name, City_Name, Station_ID)
values ('榆次', '榆次', 1549);
insert into Station (Station_Name, City_Name, Station_ID)
values ('榆社', '榆社', 1550);
insert into Station (Station_Name, City_Name, Station_ID)
values ('榕江', '榕江', 1551);
insert into Station (Station_Name, City_Name, Station_ID)
values ('樟木头东', '樟木头东', 1552);
insert into Station (Station_Name, City_Name, Station_ID)
values ('樟树', '樟树', 1553);
insert into Station (Station_Name, City_Name, Station_ID)
values ('樟树东', '樟树', 1554);
insert into Station (Station_Name, City_Name, Station_ID)
values ('横峰', '横峰', 1555);
insert into Station (Station_Name, City_Name, Station_ID)
values ('横江', '横江', 1556);
insert into Station (Station_Name, City_Name, Station_ID)
values ('横沟桥东', '横沟桥东', 1557);
insert into Station (Station_Name, City_Name, Station_ID)
values ('横道河子', '横道河子', 1558);
insert into Station (Station_Name, City_Name, Station_ID)
values ('歙县', '歙县', 1559);
insert into Station (Station_Name, City_Name, Station_ID)
values ('歙县北', '歙县', 1560);
insert into Station (Station_Name, City_Name, Station_ID)
values ('正定', '正定', 1561);
insert into Station (Station_Name, City_Name, Station_ID)
values ('正定机场', '正定机场', 1562);
insert into Station (Station_Name, City_Name, Station_ID)
values ('正镶白旗', '正镶白旗', 1563);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武义', '武义', 1564);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武义北', '武义', 1565);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武乡', '武乡', 1566);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武功', '武功', 1567);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武夷山', '武夷山', 1568);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武夷山东', '武夷山东', 1569);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武夷山北', '武夷山北', 1570);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武威', '武威', 1571);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武威南', '武威', 1572);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武安', '武安', 1573);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武山', '武山', 1574);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武当山', '武当山', 1575);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武昌', '武昌', 1576);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武汉', '武汉', 1577);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武清', '武清', 1578);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武穴', '武穴', 1579);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武胜', '武胜', 1580);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武陟', '武陟', 1581);
insert into Station (Station_Name, City_Name, Station_ID)
values ('武隆', '武隆', 1582);
insert into Station (Station_Name, City_Name, Station_ID)
values ('歪头山', '歪头山', 1583);
insert into Station (Station_Name, City_Name, Station_ID)
values ('毛告吐', '毛告吐', 1584);
insert into Station (Station_Name, City_Name, Station_ID)
values ('毛坝', '毛坝', 1585);
insert into Station (Station_Name, City_Name, Station_ID)
values ('毛坝关', '毛坝', 1586);
insert into Station (Station_Name, City_Name, Station_ID)
values ('毫州', '毫州', 1587);
insert into Station (Station_Name, City_Name, Station_ID)
values ('民乐', '民乐', 1588);
insert into Station (Station_Name, City_Name, Station_ID)
values ('民和南', '民和南', 1589);
insert into Station (Station_Name, City_Name, Station_ID)
values ('民族', '民族', 1590);
insert into Station (Station_Name, City_Name, Station_ID)
values ('民权', '民权', 1591);
insert into Station (Station_Name, City_Name, Station_ID)
values ('民福寺', '民福寺', 1592);
insert into Station (Station_Name, City_Name, Station_ID)
values ('氡泉', '氡泉', 1593);
insert into Station (Station_Name, City_Name, Station_ID)
values ('水地', '水地', 1594);
insert into Station (Station_Name, City_Name, Station_ID)
values ('水家湖', '水家湖', 1595);
insert into Station (Station_Name, City_Name, Station_ID)
values ('水富', '水富', 1596);
insert into Station (Station_Name, City_Name, Station_ID)
values ('水沟', '水沟', 1597);
insert into Station (Station_Name, City_Name, Station_ID)
values ('水泉', '水泉', 1598);
insert into Station (Station_Name, City_Name, Station_ID)
values ('水洞', '水洞', 1599);
insert into Station (Station_Name, City_Name, Station_ID)
values ('水源', '水源', 1600);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永丰营', '永丰营', 1601);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永乐店', '永乐店', 1602);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永修', '永修', 1603);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永和', '永和', 1604);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永嘉', '永嘉', 1605);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永安', '永安', 1606);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永安乡', '永安乡', 1607);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永定', '永定', 1608);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永川', '永川', 1609);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永川东', '永川', 1610);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永州', '永州', 1611);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永康', '永康', 1612);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永康南', '永康', 1613);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永泰', '永泰', 1614);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永济', '永济', 1615);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永济北', '永济', 1616);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永甸', '永甸', 1617);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永登', '永登', 1618);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永福南', '永福南', 1619);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永胜', '永胜', 1620);
insert into Station (Station_Name, City_Name, Station_ID)
values ('永郎', '永郎', 1621);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汇塘河', '汇塘河', 1622);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汇流河', '汇流河', 1623);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汉中', '汉中', 1624);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汉口', '汉口', 1625);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汉寿', '汉寿', 1626);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汉川', '汉川', 1627);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汉源', '汉源', 1628);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汉阴', '汉阴', 1629);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汐子', '汐子', 1630);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汕头', '汕头', 1631);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汕尾', '汕尾', 1632);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汗苏鲁', '汗苏鲁', 1633);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汝州', '汝州', 1634);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汝箕沟', '汝箕沟', 1635);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江华', '江华', 1636);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江宁', '江宁', 1637);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江宁西', '江宁', 1638);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江密峰', '江密峰', 1639);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江山', '江山', 1640);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江所田', '江所田', 1641);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江桥', '江桥', 1642);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江永', '江永', 1643);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江油', '江油', 1644);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江津', '江津', 1645);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江源', '江源', 1646);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江西村', '江西村', 1647);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江都', '江都', 1648);
insert into Station (Station_Name, City_Name, Station_ID)
values ('江门', '江门', 1649);
insert into Station (Station_Name, City_Name, Station_ID)
values ('池州', '池州', 1650);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汤原', '汤原', 1651);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汤头沟', '汤头沟', 1652);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汤山城', '汤山城', 1653);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汤旺河', '汤旺河', 1654);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汤池', '汤池', 1655);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汤逊湖', '汤逊湖', 1656);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汤阴', '汤阴', 1657);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汨罗', '汨罗', 1658);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汨罗东', '汨罗', 1659);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汪清', '汪清', 1660);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汾河', '汾河', 1661);
insert into Station (Station_Name, City_Name, Station_ID)
values ('汾阳', '汾阳', 1662);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沁县', '沁县', 1663);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沂南', '沂南', 1664);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沂水', '沂水', 1665);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沃皮', '沃皮', 1666);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沈丘', '沈丘', 1667);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沈家', '沈家', 1668);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沈家河', '沈家河', 1669);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沈阳', '沈阳', 1670);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沈阳北', '沈阳', 1671);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沈阳南', '沈阳', 1672);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沈阳西', '沈阳', 1673);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沐滂', '沐滂', 1674);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙园', '沙园', 1675);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙坡头', '沙坡头', 1676);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙坨子', '沙坨子', 1677);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙城', '沙城', 1678);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙岭子', '沙岭子', 1679);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙日乃', '沙日乃', 1680);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙桥', '沙桥', 1681);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙沙坡', '沙沙坡', 1682);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙沱', '沙沱', 1683);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙河市', '沙河市', 1684);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙海', '沙海', 1685);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙湾', '沙湾', 1686);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙湾县', '沙湾县', 1687);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沙马拉达', '沙马拉达', 1688);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沟口', '沟口', 1689);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沟帮子', '沟帮子', 1690);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沥林北', '沥林北', 1691);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沧州', '沧州', 1692);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沧州西', '沧州', 1693);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沭阳', '沭阳', 1694);
insert into Station (Station_Name, City_Name, Station_ID)
values ('河口北', '河口北', 1695);
insert into Station (Station_Name, City_Name, Station_ID)
values ('河口南', '河口南', 1696);
insert into Station (Station_Name, City_Name, Station_ID)
values ('河唇', '河唇', 1697);
insert into Station (Station_Name, City_Name, Station_ID)
values ('河洛营', '河洛营', 1698);
insert into Station (Station_Name, City_Name, Station_ID)
values ('河津', '河津', 1699);
insert into Station (Station_Name, City_Name, Station_ID)
values ('河源', '河源', 1700);
insert into Station (Station_Name, City_Name, Station_ID)
values ('河边', '河边', 1701);
insert into Station (Station_Name, City_Name, Station_ID)
values ('油溪', '油溪', 1702);
insert into Station (Station_Name, City_Name, Station_ID)
values ('治安', '治安', 1703);
insert into Station (Station_Name, City_Name, Station_ID)
values ('治山', '治山', 1704);
insert into Station (Station_Name, City_Name, Station_ID)
values ('沿河城', '沿河城', 1705);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泉州', '泉州', 1706);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泉水', '泉水', 1707);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泉江', '泉江', 1708);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泉阳', '泉阳', 1709);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泊头', '泊头', 1710);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泔溪', '泔溪', 1711);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泗县', '泗县', 1712);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泗水', '泗水', 1713);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泗洪', '泗洪', 1714);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泗阳', '泗阳', 1715);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泡子', '泡子', 1716);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泰和', '泰和', 1717);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泰宁', '泰宁', 1718);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泰安', '泰安', 1719);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泰山', '泰山', 1720);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泰州', '泰州', 1721);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泰康', '泰康', 1722);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泰来', '泰来', 1723);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泽普', '泽普', 1724);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泾县', '泾县', 1725);
insert into Station (Station_Name, City_Name, Station_ID)
values ('泾川', '泾川', 1726);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洋河', '洋河', 1727);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洛湾三江', '洛湾三江', 1728);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洛碛', '洛碛', 1729);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洛门', '洛门', 1730);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洛阳', '洛阳', 1731);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洛阳东', '洛阳', 1732);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洛阳龙门', '洛阳龙门', 1733);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洞庙河', '洞庙河', 1734);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洪河', '洪河', 1735);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洪洞', '洪洞', 1736);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洪洞西', '洪洞', 1737);
insert into Station (Station_Name, City_Name, Station_ID)
values ('洮南', '洮南', 1738);
insert into Station (Station_Name, City_Name, Station_ID)
values ('流水沟', '流水沟', 1739);
insert into Station (Station_Name, City_Name, Station_ID)
values ('济南', '济南', 1740);
insert into Station (Station_Name, City_Name, Station_ID)
values ('济南东', '济南', 1741);
insert into Station (Station_Name, City_Name, Station_ID)
values ('济南西', '济南', 1742);
insert into Station (Station_Name, City_Name, Station_ID)
values ('济宁', '济宁', 1743);
insert into Station (Station_Name, City_Name, Station_ID)
values ('济源', '济源', 1744);
insert into Station (Station_Name, City_Name, Station_ID)
values ('浠水', '浠水', 1745);
insert into Station (Station_Name, City_Name, Station_ID)
values ('浩良河', '浩良河', 1746);
insert into Station (Station_Name, City_Name, Station_ID)
values ('浮图峪', '浮图峪', 1747);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海东西', '海东西', 1748);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海伦', '海伦', 1749);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海北', '海北', 1750);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海口', '海口', 1751);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海口东', '海口', 1752);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海坨子', '海坨子', 1753);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海城', '海城', 1754);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海城西', '海城', 1755);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海宁', '海宁', 1756);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海宁西', '海宁', 1757);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海安县', '海安县', 1758);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海拉尔', '海拉尔', 1759);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海林', '海林', 1760);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海浪', '海浪', 1761);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海石湾', '海石湾', 1762);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海阳', '海阳', 1763);
insert into Station (Station_Name, City_Name, Station_ID)
values ('海阳北', '海阳', 1764);
insert into Station (Station_Name, City_Name, Station_ID)
values ('涉县', '涉县', 1765);
insert into Station (Station_Name, City_Name, Station_ID)
values ('涞源', '涞源', 1766);
insert into Station (Station_Name, City_Name, Station_ID)
values ('涟源', '涟源', 1767);
insert into Station (Station_Name, City_Name, Station_ID)
values ('涡阳', '涡阳', 1768);
insert into Station (Station_Name, City_Name, Station_ID)
values ('涪陵', '涪陵', 1769);
insert into Station (Station_Name, City_Name, Station_ID)
values ('涪陵北', '涪陵', 1770);
insert into Station (Station_Name, City_Name, Station_ID)
values ('涵江', '涵江', 1771);
insert into Station (Station_Name, City_Name, Station_ID)
values ('涿州', '涿州', 1772);
insert into Station (Station_Name, City_Name, Station_ID)
values ('涿州东', '涿州', 1773);
insert into Station (Station_Name, City_Name, Station_ID)
values ('淄博', '淄博', 1774);
insert into Station (Station_Name, City_Name, Station_ID)
values ('淮北', '淮北', 1775);
insert into Station (Station_Name, City_Name, Station_ID)
values ('淮南', '淮南', 1776);
insert into Station (Station_Name, City_Name, Station_ID)
values ('淮南东', '淮南', 1777);
insert into Station (Station_Name, City_Name, Station_ID)
values ('淮安', '淮安', 1778);
insert into Station (Station_Name, City_Name, Station_ID)
values ('淮滨', '淮滨', 1779);
insert into Station (Station_Name, City_Name, Station_ID)
values ('深井子', '深井子', 1780);
insert into Station (Station_Name, City_Name, Station_ID)
values ('深圳', '深圳', 1781);
insert into Station (Station_Name, City_Name, Station_ID)
values ('深圳东', '深圳', 1782);
insert into Station (Station_Name, City_Name, Station_ID)
values ('深圳北', '深圳', 1783);
insert into Station (Station_Name, City_Name, Station_ID)
values ('深圳坪山', '深圳坪山', 1784);
insert into Station (Station_Name, City_Name, Station_ID)
values ('深圳西', '深圳', 1785);
insert into Station (Station_Name, City_Name, Station_ID)
values ('深州', '深州', 1786);
insert into Station (Station_Name, City_Name, Station_ID)
values ('清华园', '清华园', 1787);
insert into Station (Station_Name, City_Name, Station_ID)
values ('清原', '清原', 1788);
insert into Station (Station_Name, City_Name, Station_ID)
values ('清徐', '清徐', 1789);
insert into Station (Station_Name, City_Name, Station_ID)
values ('清水', '清水', 1790);
insert into Station (Station_Name, City_Name, Station_ID)
values ('清水北', '清水', 1791);
insert into Station (Station_Name, City_Name, Station_ID)
values ('清河', '清河', 1792);
insert into Station (Station_Name, City_Name, Station_ID)
values ('清河城', '清河城', 1793);
insert into Station (Station_Name, City_Name, Station_ID)
values ('清河门', '清河门', 1794);
insert into Station (Station_Name, City_Name, Station_ID)
values ('清涧县', '清涧县', 1795);
insert into Station (Station_Name, City_Name, Station_ID)
values ('清远', '清远', 1796);
insert into Station (Station_Name, City_Name, Station_ID)
values ('渑池', '渑池', 1797);
insert into Station (Station_Name, City_Name, Station_ID)
values ('渠县', '渠县', 1798);
insert into Station (Station_Name, City_Name, Station_ID)
values ('渠旧', '渠旧', 1799);
insert into Station (Station_Name, City_Name, Station_ID)
values ('渠黎', '渠黎', 1800);
insert into Station (Station_Name, City_Name, Station_ID)
values ('渡市', '渡市', 1801);
insert into Station (Station_Name, City_Name, Station_ID)
values ('温岭', '温岭', 1802);
insert into Station (Station_Name, City_Name, Station_ID)
values ('温州', '温州', 1803);
insert into Station (Station_Name, City_Name, Station_ID)
values ('温州南', '温州', 1804);
insert into Station (Station_Name, City_Name, Station_ID)
values ('温春', '温春', 1805);
insert into Station (Station_Name, City_Name, Station_ID)
values ('温泉寺', '温泉寺', 1806);
insert into Station (Station_Name, City_Name, Station_ID)
values ('温都和硕', '温都和硕', 1807);
insert into Station (Station_Name, City_Name, Station_ID)
values ('渭南', '渭南', 1808);
insert into Station (Station_Name, City_Name, Station_ID)
values ('渭南北', '渭南', 1809);
insert into Station (Station_Name, City_Name, Station_ID)
values ('渭南镇', '渭南镇', 1810);
insert into Station (Station_Name, City_Name, Station_ID)
values ('湖口', '湖口', 1811);
insert into Station (Station_Name, City_Name, Station_ID)
values ('湖州', '湖州', 1812);
insert into Station (Station_Name, City_Name, Station_ID)
values ('湘乡', '湘乡', 1813);
insert into Station (Station_Name, City_Name, Station_ID)
values ('湘潭', '湘潭', 1814);
insert into Station (Station_Name, City_Name, Station_ID)
values ('湘潭北', '湘潭', 1815);
insert into Station (Station_Name, City_Name, Station_ID)
values ('湛江', '湛江', 1816);
insert into Station (Station_Name, City_Name, Station_ID)
values ('湛江西', '湛江', 1817);
insert into Station (Station_Name, City_Name, Station_ID)
values ('湟源', '湟源', 1818);
insert into Station (Station_Name, City_Name, Station_ID)
values ('湾沟', '湾沟', 1819);
insert into Station (Station_Name, City_Name, Station_ID)
values ('溆浦', '溆浦', 1820);
insert into Station (Station_Name, City_Name, Station_ID)
values ('溆浦南', '溆浦', 1821);
insert into Station (Station_Name, City_Name, Station_ID)
values ('源潭', '源潭', 1822);
insert into Station (Station_Name, City_Name, Station_ID)
values ('源迁', '源迁', 1823);
insert into Station (Station_Name, City_Name, Station_ID)
values ('溧水', '溧水', 1824);
insert into Station (Station_Name, City_Name, Station_ID)
values ('溧阳', '溧阳', 1825);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滁州', '滁州', 1826);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滁州北', '滁州', 1827);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滕州', '滕州', 1828);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滕州东', '滕州', 1829);
insert into Station (Station_Name, City_Name, Station_ID)
values ('满归', '满归', 1830);
insert into Station (Station_Name, City_Name, Station_ID)
values ('满洲里', '满洲里', 1831);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滥坝', '滥坝', 1832);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滦县', '滦县', 1833);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滦平', '滦平', 1834);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滦河', '滦河', 1835);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滦河沿', '滦河沿', 1836);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滨州', '滨州', 1837);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滨江', '滨江', 1838);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滨海', '滨海', 1839);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滨海北', '滨海', 1840);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滩头', '滩头', 1841);
insert into Station (Station_Name, City_Name, Station_ID)
values ('滴道', '滴道', 1842);
insert into Station (Station_Name, City_Name, Station_ID)
values ('漠河', '漠河', 1843);
insert into Station (Station_Name, City_Name, Station_ID)
values ('漯河', '漯河', 1844);
insert into Station (Station_Name, City_Name, Station_ID)
values ('漯河西', '漯河', 1845);
insert into Station (Station_Name, City_Name, Station_ID)
values ('漳州', '漳州', 1846);
insert into Station (Station_Name, City_Name, Station_ID)
values ('漳州东', '漳州', 1847);
insert into Station (Station_Name, City_Name, Station_ID)
values ('漳平', '漳平', 1848);
insert into Station (Station_Name, City_Name, Station_ID)
values ('漳浦', '漳浦', 1849);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潍坊', '潍坊', 1850);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潘家店', '潘家店', 1851);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潜江', '潜江', 1852);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潞城', '潞城', 1853);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潢川', '潢川', 1854);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潮州', '潮州', 1855);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潮水', '潮水', 1856);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潮汕', '潮汕', 1857);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潮阳', '潮阳', 1858);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潼关', '潼关', 1859);
insert into Station (Station_Name, City_Name, Station_ID)
values ('潼南', '潼南', 1860);
insert into Station (Station_Name, City_Name, Station_ID)
values ('澧县', '澧县', 1861);
insert into Station (Station_Name, City_Name, Station_ID)
values ('濑湍', '濑湍', 1862);
insert into Station (Station_Name, City_Name, Station_ID)
values ('濮阳', '濮阳', 1863);
insert into Station (Station_Name, City_Name, Station_ID)
values ('灌水', '灌水', 1864);
insert into Station (Station_Name, City_Name, Station_ID)
values ('火炬沟', '火炬沟', 1865);
insert into Station (Station_Name, City_Name, Station_ID)
values ('火烧寨', '火烧寨', 1866);
insert into Station (Station_Name, City_Name, Station_ID)
values ('灯塔', '灯塔', 1867);
insert into Station (Station_Name, City_Name, Station_ID)
values ('灵丘', '灵丘', 1868);
insert into Station (Station_Name, City_Name, Station_ID)
values ('灵宝', '灵宝', 1869);
insert into Station (Station_Name, City_Name, Station_ID)
values ('灵山', '灵山', 1870);
insert into Station (Station_Name, City_Name, Station_ID)
values ('灵武', '灵武', 1871);
insert into Station (Station_Name, City_Name, Station_ID)
values ('灵璧', '灵璧', 1872);
insert into Station (Station_Name, City_Name, Station_ID)
values ('灵石', '灵石', 1873);
insert into Station (Station_Name, City_Name, Station_ID)
values ('灵石东', '灵石', 1874);
insert into Station (Station_Name, City_Name, Station_ID)
values ('炎陵', '炎陵', 1875);
insert into Station (Station_Name, City_Name, Station_ID)
values ('烟台', '烟台', 1876);
insert into Station (Station_Name, City_Name, Station_ID)
values ('烟台南', '烟台', 1877);
insert into Station (Station_Name, City_Name, Station_ID)
values ('烟筒屯', '烟筒屯', 1878);
insert into Station (Station_Name, City_Name, Station_ID)
values ('烟筒山', '烟筒山', 1879);
insert into Station (Station_Name, City_Name, Station_ID)
values ('热水', '热水', 1880);
insert into Station (Station_Name, City_Name, Station_ID)
values ('焉耆', '焉耆', 1881);
insert into Station (Station_Name, City_Name, Station_ID)
values ('焦作', '焦作', 1882);
insert into Station (Station_Name, City_Name, Station_ID)
values ('煤田', '煤田', 1883);
insert into Station (Station_Name, City_Name, Station_ID)
values ('照福铺', '照福铺', 1884);
insert into Station (Station_Name, City_Name, Station_ID)
values ('熊岳城', '熊岳城', 1885);
insert into Station (Station_Name, City_Name, Station_ID)
values ('燕子砭', '燕子砭', 1886);
insert into Station (Station_Name, City_Name, Station_ID)
values ('燕家庄', '燕家庄', 1887);
insert into Station (Station_Name, City_Name, Station_ID)
values ('燕山', '燕山', 1888);
insert into Station (Station_Name, City_Name, Station_ID)
values ('燕岗', '燕岗', 1889);
insert into Station (Station_Name, City_Name, Station_ID)
values ('燕郊', '燕郊', 1890);
insert into Station (Station_Name, City_Name, Station_ID)
values ('爱河', '爱河', 1891);
insert into Station (Station_Name, City_Name, Station_ID)
values ('牙克石', '牙克石', 1892);
insert into Station (Station_Name, City_Name, Station_ID)
values ('牙屯堡', '牙屯堡', 1893);
insert into Station (Station_Name, City_Name, Station_ID)
values ('牙拉盖图', '牙拉盖图', 1894);
insert into Station (Station_Name, City_Name, Station_ID)
values ('牛家', '牛家', 1895);
insert into Station (Station_Name, City_Name, Station_ID)
values ('牛家营子', '牛家营子', 1896);
insert into Station (Station_Name, City_Name, Station_ID)
values ('牛庄', '牛庄', 1897);
insert into Station (Station_Name, City_Name, Station_ID)
values ('牛汾台', '牛汾台', 1898);
insert into Station (Station_Name, City_Name, Station_ID)
values ('牟平', '牟平', 1899);
insert into Station (Station_Name, City_Name, Station_ID)
values ('牡丹江', '牡丹江', 1900);
insert into Station (Station_Name, City_Name, Station_ID)
values ('牧原', '牧原', 1901);
insert into Station (Station_Name, City_Name, Station_ID)
values ('犀浦', '犀浦', 1902);
insert into Station (Station_Name, City_Name, Station_ID)
values ('犀浦东', '犀浦', 1903);
insert into Station (Station_Name, City_Name, Station_ID)
values ('独山', '独山', 1904);
insert into Station (Station_Name, City_Name, Station_ID)
values ('狮子营', '狮子营', 1905);
insert into Station (Station_Name, City_Name, Station_ID)
values ('狮山', '狮山', 1906);
insert into Station (Station_Name, City_Name, Station_ID)
values ('狮山北', '狮山北', 1907);
insert into Station (Station_Name, City_Name, Station_ID)
values ('猛洞河', '猛洞河', 1908);
insert into Station (Station_Name, City_Name, Station_ID)
values ('猛鹫山', '猛鹫山', 1909);
insert into Station (Station_Name, City_Name, Station_ID)
values ('猴山', '猴山', 1910);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玉屏', '玉屏', 1911);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玉山', '玉山', 1912);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玉山南', '玉山南', 1913);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玉林', '玉林', 1914);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玉泉', '玉泉', 1915);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玉溪', '玉溪', 1916);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玉田县', '玉田县', 1917);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玉石', '玉石', 1918);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玉舍', '玉舍', 1919);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玉门', '玉门', 1920);
insert into Station (Station_Name, City_Name, Station_ID)
values ('王团庄', '王团庄', 1921);
insert into Station (Station_Name, City_Name, Station_ID)
values ('王场', '王场', 1922);
insert into Station (Station_Name, City_Name, Station_ID)
values ('王安镇', '王安镇', 1923);
insert into Station (Station_Name, City_Name, Station_ID)
values ('王家营西', '王家营西', 1924);
insert into Station (Station_Name, City_Name, Station_ID)
values ('王岗', '王岗', 1925);
insert into Station (Station_Name, City_Name, Station_ID)
values ('王庄', '王庄', 1926);
insert into Station (Station_Name, City_Name, Station_ID)
values ('王府', '王府', 1927);
insert into Station (Station_Name, City_Name, Station_ID)
values ('玛纳斯', '玛纳斯', 1928);
insert into Station (Station_Name, City_Name, Station_ID)
values ('珠斯花', '珠斯花', 1929);
insert into Station (Station_Name, City_Name, Station_ID)
values ('珠海', '珠海', 1930);
insert into Station (Station_Name, City_Name, Station_ID)
values ('珠海北', '珠海', 1931);
insert into Station (Station_Name, City_Name, Station_ID)
values ('珠窝', '珠窝', 1932);
insert into Station (Station_Name, City_Name, Station_ID)
values ('班猫箐', '班猫箐', 1933);
insert into Station (Station_Name, City_Name, Station_ID)
values ('珲春', '珲春', 1934);
insert into Station (Station_Name, City_Name, Station_ID)
values ('琼海', '琼海', 1935);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瑞安', '瑞安', 1936);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瑞昌', '瑞昌', 1937);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瑞金', '瑞金', 1938);
insert into Station (Station_Name, City_Name, Station_ID)
values ('璧山', '璧山', 1939);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瓜州', '瓜州', 1940);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瓢儿屯', '瓢儿屯', 1941);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瓦屋山', '瓦屋山', 1942);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瓦房', '瓦房', 1943);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瓦房店', '瓦房店', 1944);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瓦房店西', '瓦房店', 1945);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瓦拉干', '瓦拉干', 1946);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瓦祖', '瓦祖', 1947);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瓦窑坝', '瓦窑坝', 1948);
insert into Station (Station_Name, City_Name, Station_ID)
values ('瓦窑田', '瓦窑田', 1949);
insert into Station (Station_Name, City_Name, Station_ID)
values ('甘旗卡', '甘旗卡', 1950);
insert into Station (Station_Name, City_Name, Station_ID)
values ('甘河', '甘河', 1951);
insert into Station (Station_Name, City_Name, Station_ID)
values ('甘泉北', '甘泉北', 1952);
insert into Station (Station_Name, City_Name, Station_ID)
values ('甘洛', '甘洛', 1953);
insert into Station (Station_Name, City_Name, Station_ID)
values ('甘草店', '甘草店', 1954);
insert into Station (Station_Name, City_Name, Station_ID)
values ('甘谷', '甘谷', 1955);
insert into Station (Station_Name, City_Name, Station_ID)
values ('田东北', '田东北', 1956);
insert into Station (Station_Name, City_Name, Station_ID)
values ('田家沟', '田家沟', 1957);
insert into Station (Station_Name, City_Name, Station_ID)
values ('田师府', '田师府', 1958);
insert into Station (Station_Name, City_Name, Station_ID)
values ('田林', '田林', 1959);
insert into Station (Station_Name, City_Name, Station_ID)
values ('田梁子', '田梁子', 1960);
insert into Station (Station_Name, City_Name, Station_ID)
values ('田阳', '田阳', 1961);
insert into Station (Station_Name, City_Name, Station_ID)
values ('甲山', '甲山', 1962);
insert into Station (Station_Name, City_Name, Station_ID)
values ('申家店', '申家店', 1963);
insert into Station (Station_Name, City_Name, Station_ID)
values ('甸心', '甸心', 1964);
insert into Station (Station_Name, City_Name, Station_ID)
values ('界首市', '界首市', 1965);
insert into Station (Station_Name, City_Name, Station_ID)
values ('留庄', '留庄', 1966);
insert into Station (Station_Name, City_Name, Station_ID)
values ('略阳', '略阳', 1967);
insert into Station (Station_Name, City_Name, Station_ID)
values ('疏勒河', '疏勒河', 1968);
insert into Station (Station_Name, City_Name, Station_ID)
values ('登沙河', '登沙河', 1969);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白云鄂博', '白云鄂博', 1970);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白合', '白合', 1971);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白城', '白城', 1972);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白壁关', '白壁关', 1973);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白奎堡', '白奎堡', 1974);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白山乡', '白山乡', 1975);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白山市', '白山市', 1976);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白彦花', '白彦花', 1977);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白旗', '白旗', 1978);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白果', '白果', 1979);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白桦排', '白桦排', 1980);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白水江', '白水江', 1981);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白水镇', '白水镇', 1982);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白沙', '白沙', 1983);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白沙坡', '白沙坡', 1984);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白沙沱', '白沙沱', 1985);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白沟', '白沟', 1986);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白河', '白河', 1987);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白河东', '白河', 1988);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白河县', '白河县', 1989);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白洋淀', '白洋淀', 1990);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白涛', '白涛', 1991);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白涧', '白涧', 1992);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白狼', '白狼', 1993);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白石山', '白石山', 1994);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白石岩', '白石岩', 1995);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白芨沟', '白芨沟', 1996);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白银哈尔', '白银哈尔', 1997);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白银市', '白银市', 1998);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白银西', '白银西', 1999);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白音他拉', '白音他拉', 2000);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白音华南', '白音华南', 2001);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白音察干', '白音察干', 2002);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白音胡硕', '白音胡硕', 2003);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白马', '白马', 2004);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白马井', '白马井', 2005);
insert into Station (Station_Name, City_Name, Station_ID)
values ('白鸡坡', '白鸡坡', 2006);
insert into Station (Station_Name, City_Name, Station_ID)
values ('百宜', '百宜', 2007);
insert into Station (Station_Name, City_Name, Station_ID)
values ('百色', '百色', 2008);
insert into Station (Station_Name, City_Name, Station_ID)
values ('百里峡', '百里峡', 2009);
insert into Station (Station_Name, City_Name, Station_ID)
values ('皋兰', '皋兰', 2010);
insert into Station (Station_Name, City_Name, Station_ID)
values ('皮口', '皮口', 2011);
insert into Station (Station_Name, City_Name, Station_ID)
values ('皮山', '皮山', 2012);
insert into Station (Station_Name, City_Name, Station_ID)
values ('益阳', '益阳', 2013);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盐城', '盐城', 2014);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盐池', '盐池', 2015);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盐津', '盐津', 2016);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盐津北', '盐津', 2017);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盖州', '盖州', 2018);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盖州西', '盖州', 2019);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盘关', '盘关', 2020);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盘古', '盘古', 2021);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盘古寺', '盘古寺', 2022);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盘锦', '盘锦', 2023);
insert into Station (Station_Name, City_Name, Station_ID)
values ('盘锦北', '盘锦', 2024);
insert into Station (Station_Name, City_Name, Station_ID)
values ('眉山', '眉山', 2025);
insert into Station (Station_Name, City_Name, Station_ID)
values ('眉山东', '眉山', 2026);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石人城', '石人城', 2027);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石嘴山', '石嘴山', 2028);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石场', '石场', 2029);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石坝', '石坝', 2030);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石城', '石城', 2031);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石头', '石头', 2032);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石家庄', '石家庄', 2033);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石家庄北', '石家庄', 2034);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石山', '石山', 2035);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石岭', '石岭', 2036);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石峡子', '石峡子', 2037);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石林', '石林', 2038);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石林南', '石林', 2039);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石柱县', '石柱县', 2040);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石桥子', '石桥子', 2041);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石河子', '石河子', 2042);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石泉县', '石泉县', 2043);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石湖', '石湖', 2044);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石磷', '石磷', 2045);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石脑', '石脑', 2046);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石门县北', '石门县北', 2047);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石门坎', '石门坎', 2048);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石门子', '石门子', 2049);
insert into Station (Station_Name, City_Name, Station_ID)
values ('石门村', '石门村', 2050);
insert into Station (Station_Name, City_Name, Station_ID)
values ('砀山', '砀山', 2051);
insert into Station (Station_Name, City_Name, Station_ID)
values ('砚川', '砚川', 2052);
insert into Station (Station_Name, City_Name, Station_ID)
values ('砬子河', '砬子河', 2053);
insert into Station (Station_Name, City_Name, Station_ID)
values ('确山', '确山', 2054);
insert into Station (Station_Name, City_Name, Station_ID)
values ('碧州', '碧州', 2055);
insert into Station (Station_Name, City_Name, Station_ID)
values ('碧江', '碧江', 2056);
insert into Station (Station_Name, City_Name, Station_ID)
values ('碱柜', '碱柜', 2057);
insert into Station (Station_Name, City_Name, Station_ID)
values ('碾子山', '碾子山', 2058);
insert into Station (Station_Name, City_Name, Station_ID)
values ('磁县', '磁县', 2059);
insert into Station (Station_Name, City_Name, Station_ID)
values ('磁山', '磁山', 2060);
insert into Station (Station_Name, City_Name, Station_ID)
values ('磁窑', '磁窑', 2061);
insert into Station (Station_Name, City_Name, Station_ID)
values ('磐安镇', '磐安镇', 2062);
insert into Station (Station_Name, City_Name, Station_ID)
values ('磐石', '磐石', 2063);
insert into Station (Station_Name, City_Name, Station_ID)
values ('磨刀石', '磨刀石', 2064);
insert into Station (Station_Name, City_Name, Station_ID)
values ('磨溪', '磨溪', 2065);
insert into Station (Station_Name, City_Name, Station_ID)
values ('磨滩', '磨滩', 2066);
insert into Station (Station_Name, City_Name, Station_ID)
values ('礼泉', '礼泉', 2067);
insert into Station (Station_Name, City_Name, Station_ID)
values ('祁东', '祁东', 2068);
insert into Station (Station_Name, City_Name, Station_ID)
values ('祁县', '祁县', 2069);
insert into Station (Station_Name, City_Name, Station_ID)
values ('祁县东', '祁县', 2070);
insert into Station (Station_Name, City_Name, Station_ID)
values ('祁家堡', '祁家堡', 2071);
insert into Station (Station_Name, City_Name, Station_ID)
values ('祁门', '祁门', 2072);
insert into Station (Station_Name, City_Name, Station_ID)
values ('祁阳', '祁阳', 2073);
insert into Station (Station_Name, City_Name, Station_ID)
values ('神头', '神头', 2074);
insert into Station (Station_Name, City_Name, Station_ID)
values ('神峪河', '神峪河', 2075);
insert into Station (Station_Name, City_Name, Station_ID)
values ('神州', '神州', 2076);
insert into Station (Station_Name, City_Name, Station_ID)
values ('神木', '神木', 2077);
insert into Station (Station_Name, City_Name, Station_ID)
values ('神树', '神树', 2078);
insert into Station (Station_Name, City_Name, Station_ID)
values ('神池', '神池', 2079);
insert into Station (Station_Name, City_Name, Station_ID)
values ('祥云', '祥云', 2080);
insert into Station (Station_Name, City_Name, Station_ID)
values ('禄丰南', '禄丰南', 2081);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福兴地', '福兴地', 2082);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福利屯', '福利屯', 2083);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福安', '福安', 2084);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福山口', '福山口', 2085);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福山镇', '福山镇', 2086);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福州', '福州', 2087);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福州南', '福州', 2088);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福巨', '福巨', 2089);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福泉', '福泉', 2090);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福海', '福海', 2091);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福清', '福清', 2092);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福生庄', '福生庄', 2093);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福田', '福田', 2094);
insert into Station (Station_Name, City_Name, Station_ID)
values ('福鼎', '福鼎', 2095);
insert into Station (Station_Name, City_Name, Station_ID)
values ('禹城', '禹城', 2096);
insert into Station (Station_Name, City_Name, Station_ID)
values ('离堆公园', '离堆公园', 2097);
insert into Station (Station_Name, City_Name, Station_ID)
values ('秀山', '秀山', 2098);
insert into Station (Station_Name, City_Name, Station_ID)
values ('秋木庄', '秋木庄', 2099);
insert into Station (Station_Name, City_Name, Station_ID)
values ('秦家', '秦家', 2100);
insert into Station (Station_Name, City_Name, Station_ID)
values ('秦家庄', '秦家庄', 2101);
insert into Station (Station_Name, City_Name, Station_ID)
values ('秦岭', '秦岭', 2102);
insert into Station (Station_Name, City_Name, Station_ID)
values ('秦皇岛', '秦皇岛', 2103);
insert into Station (Station_Name, City_Name, Station_ID)
values ('秧草地', '秧草地', 2104);
insert into Station (Station_Name, City_Name, Station_ID)
values ('稷山', '稷山', 2105);
insert into Station (Station_Name, City_Name, Station_ID)
values ('穆棱', '穆棱', 2106);
insert into Station (Station_Name, City_Name, Station_ID)
values ('窑上', '窑上', 2107);
insert into Station (Station_Name, City_Name, Station_ID)
values ('立志', '立志', 2108);
insert into Station (Station_Name, City_Name, Station_ID)
values ('章丘', '章丘', 2109);
insert into Station (Station_Name, City_Name, Station_ID)
values ('章党', '章党', 2110);
insert into Station (Station_Name, City_Name, Station_ID)
values ('章古台', '章古台', 2111);
insert into Station (Station_Name, City_Name, Station_ID)
values ('端州', '端州', 2112);
insert into Station (Station_Name, City_Name, Station_ID)
values ('竹园坝', '竹园坝', 2113);
insert into Station (Station_Name, City_Name, Station_ID)
values ('笔架山', '笔架山', 2114);
insert into Station (Station_Name, City_Name, Station_ID)
values ('简阳', '简阳', 2115);
insert into Station (Station_Name, City_Name, Station_ID)
values ('简阳南', '简阳', 2116);
insert into Station (Station_Name, City_Name, Station_ID)
values ('米易', '米易', 2117);
insert into Station (Station_Name, City_Name, Station_ID)
values ('米沙子', '米沙子', 2118);
insert into Station (Station_Name, City_Name, Station_ID)
values ('米脂', '米脂', 2119);
insert into Station (Station_Name, City_Name, Station_ID)
values ('精河南', '精河南', 2120);
insert into Station (Station_Name, City_Name, Station_ID)
values ('索伦', '索伦', 2121);
insert into Station (Station_Name, City_Name, Station_ID)
values ('索图罕', '索图罕', 2122);
insert into Station (Station_Name, City_Name, Station_ID)
values ('紫荆关', '紫荆关', 2123);
insert into Station (Station_Name, City_Name, Station_ID)
values ('紫阳', '紫阳', 2124);
insert into Station (Station_Name, City_Name, Station_ID)
values ('綦江', '綦江', 2125);
insert into Station (Station_Name, City_Name, Station_ID)
values ('繁峙', '繁峙', 2126);
insert into Station (Station_Name, City_Name, Station_ID)
values ('繁昌西', '繁昌西', 2127);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红光镇', '红光镇', 2128);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红兴隆', '红兴隆', 2129);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红安西', '红安西', 2130);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红寺堡', '红寺堡', 2131);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红山', '红山', 2132);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红岘台', '红岘台', 2133);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红峰', '红峰', 2134);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红彦', '红彦', 2135);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红旗营', '红旗营', 2136);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红星', '红星', 2137);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红果', '红果', 2138);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红江', '红江', 2139);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红砂坝', '红砂坝', 2140);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红砂岘', '红砂岘', 2141);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红花园', '红花园', 2142);
insert into Station (Station_Name, City_Name, Station_ID)
values ('红花沟', '红花沟', 2143);
insert into Station (Station_Name, City_Name, Station_ID)
values ('纪家沟', '纪家沟', 2144);
insert into Station (Station_Name, City_Name, Station_ID)
values ('纳雍', '纳雍', 2145);
insert into Station (Station_Name, City_Name, Station_ID)
values ('纸坊东', '纸坊东', 2146);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绅坊', '绅坊', 2147);
insert into Station (Station_Name, City_Name, Station_ID)
values ('织金', '织金', 2148);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绍兴', '绍兴', 2149);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绍兴北', '绍兴', 2150);
insert into Station (Station_Name, City_Name, Station_ID)
values ('经棚', '经棚', 2151);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绕阳河', '绕阳河', 2152);
insert into Station (Station_Name, City_Name, Station_ID)
values ('统军庄', '统军庄', 2153);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绣峰', '绣峰', 2154);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绥中', '绥中', 2155);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绥中北', '绥中', 2156);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绥化', '绥化', 2157);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绥德', '绥德', 2158);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绥棱', '绥棱', 2159);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绥芬河', '绥芬河', 2160);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绥阳', '绥阳', 2161);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绩溪北', '绩溪北', 2162);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绩溪县', '绩溪县', 2163);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绵阳', '绵阳', 2164);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绿化', '绿化', 2165);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绿博园', '绿博园', 2166);
insert into Station (Station_Name, City_Name, Station_ID)
values ('绿潭', '绿潭', 2167);
insert into Station (Station_Name, City_Name, Station_ID)
values ('缙云', '缙云', 2168);
insert into Station (Station_Name, City_Name, Station_ID)
values ('缙云西', '缙云', 2169);
insert into Station (Station_Name, City_Name, Station_ID)
values ('罗城', '罗城', 2170);
insert into Station (Station_Name, City_Name, Station_ID)
values ('罗山', '罗山', 2171);
insert into Station (Station_Name, City_Name, Station_ID)
values ('罗平', '罗平', 2172);
insert into Station (Station_Name, City_Name, Station_ID)
values ('罗江东', '罗江东', 2173);
insert into Station (Station_Name, City_Name, Station_ID)
values ('罗源', '罗源', 2174);
insert into Station (Station_Name, City_Name, Station_ID)
values ('羊圈子', '羊圈子', 2175);
insert into Station (Station_Name, City_Name, Station_ID)
values ('羊场', '羊场', 2176);
insert into Station (Station_Name, City_Name, Station_ID)
values ('羊坪', '羊坪', 2177);
insert into Station (Station_Name, City_Name, Station_ID)
values ('羊堡', '羊堡', 2178);
insert into Station (Station_Name, City_Name, Station_ID)
values ('羊尾哨', '羊尾哨', 2179);
insert into Station (Station_Name, City_Name, Station_ID)
values ('羊者窝', '羊者窝', 2180);
insert into Station (Station_Name, City_Name, Station_ID)
values ('羊臼河', '羊臼河', 2181);
insert into Station (Station_Name, City_Name, Station_ID)
values ('羊草', '羊草', 2182);
insert into Station (Station_Name, City_Name, Station_ID)
values ('美兰', '美兰', 2183);
insert into Station (Station_Name, City_Name, Station_ID)
values ('美岱召', '美岱召', 2184);
insert into Station (Station_Name, City_Name, Station_ID)
values ('美溪', '美溪', 2185);
insert into Station (Station_Name, City_Name, Station_ID)
values ('翠岗', '翠岗', 2186);
insert into Station (Station_Name, City_Name, Station_ID)
values ('翠峰', '翠峰', 2187);
insert into Station (Station_Name, City_Name, Station_ID)
values ('老城镇', '老城镇', 2188);
insert into Station (Station_Name, City_Name, Station_ID)
values ('老岭', '老岭', 2189);
insert into Station (Station_Name, City_Name, Station_ID)
values ('老府', '老府', 2190);
insert into Station (Station_Name, City_Name, Station_ID)
values ('老爷岭', '老爷岭', 2191);
insert into Station (Station_Name, City_Name, Station_ID)
values ('老羊壕', '老羊壕', 2192);
insert into Station (Station_Name, City_Name, Station_ID)
values ('老莱', '老莱', 2193);
insert into Station (Station_Name, City_Name, Station_ID)
values ('老营', '老营', 2194);
insert into Station (Station_Name, City_Name, Station_ID)
values ('老边', '老边', 2195);
insert into Station (Station_Name, City_Name, Station_ID)
values ('耒阳', '耒阳', 2196);
insert into Station (Station_Name, City_Name, Station_ID)
values ('耒阳西', '耒阳', 2197);
insert into Station (Station_Name, City_Name, Station_ID)
values ('聂河', '聂河', 2198);
insert into Station (Station_Name, City_Name, Station_ID)
values ('聊城', '聊城', 2199);
insert into Station (Station_Name, City_Name, Station_ID)
values ('联合乡', '联合乡', 2200);
insert into Station (Station_Name, City_Name, Station_ID)
values ('肃宁', '肃宁', 2201);
insert into Station (Station_Name, City_Name, Station_ID)
values ('肇东', '肇东', 2202);
insert into Station (Station_Name, City_Name, Station_ID)
values ('肇庆', '肇庆', 2203);
insert into Station (Station_Name, City_Name, Station_ID)
values ('肇庆东', '肇庆', 2204);
insert into Station (Station_Name, City_Name, Station_ID)
values ('肥东', '肥东', 2205);
insert into Station (Station_Name, City_Name, Station_ID)
values ('背荫河', '背荫河', 2206);
insert into Station (Station_Name, City_Name, Station_ID)
values ('胜芳', '胜芳', 2207);
insert into Station (Station_Name, City_Name, Station_ID)
values ('胶州', '胶州', 2208);
insert into Station (Station_Name, City_Name, Station_ID)
values ('胶州北', '胶州', 2209);
insert into Station (Station_Name, City_Name, Station_ID)
values ('能家', '能家', 2210);
insert into Station (Station_Name, City_Name, Station_ID)
values ('腰栈', '腰栈', 2211);
insert into Station (Station_Name, City_Name, Station_ID)
values ('自贡', '自贡', 2212);
insert into Station (Station_Name, City_Name, Station_ID)
values ('舍伯吐', '舍伯吐', 2213);
insert into Station (Station_Name, City_Name, Station_ID)
values ('舍力虎', '舍力虎', 2214);
insert into Station (Station_Name, City_Name, Station_ID)
values ('舒兰', '舒兰', 2215);
insert into Station (Station_Name, City_Name, Station_ID)
values ('舒城', '舒城', 2216);
insert into Station (Station_Name, City_Name, Station_ID)
values ('良各庄', '良各庄', 2217);
insert into Station (Station_Name, City_Name, Station_ID)
values ('艾不盖', '艾不盖', 2218);
insert into Station (Station_Name, City_Name, Station_ID)
values ('艾家村', '艾家村', 2219);
insert into Station (Station_Name, City_Name, Station_ID)
values ('艾河', '艾河', 2220);
insert into Station (Station_Name, City_Name, Station_ID)
values ('芜湖', '芜湖', 2221);
insert into Station (Station_Name, City_Name, Station_ID)
values ('芦台', '芦台', 2222);
insert into Station (Station_Name, City_Name, Station_ID)
values ('芦家庄', '芦家庄', 2223);
insert into Station (Station_Name, City_Name, Station_ID)
values ('芦家村', '芦家村', 2224);
insert into Station (Station_Name, City_Name, Station_ID)
values ('芦沟', '芦沟', 2225);
insert into Station (Station_Name, City_Name, Station_ID)
values ('芨岭', '芨岭', 2226);
insert into Station (Station_Name, City_Name, Station_ID)
values ('花园', '花园', 2227);
insert into Station (Station_Name, City_Name, Station_ID)
values ('花园口', '花园口', 2228);
insert into Station (Station_Name, City_Name, Station_ID)
values ('花土坡', '花土坡', 2229);
insert into Station (Station_Name, City_Name, Station_ID)
values ('花家庄', '花家庄', 2230);
insert into Station (Station_Name, City_Name, Station_ID)
values ('花桥', '花桥', 2231);
insert into Station (Station_Name, City_Name, Station_ID)
values ('花棚子', '花棚子', 2232);
insert into Station (Station_Name, City_Name, Station_ID)
values ('芷江', '芷江', 2233);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苇河', '苇河', 2234);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苍南', '苍南', 2235);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苍坪', '苍坪', 2236);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苍溪', '苍溪', 2237);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苍石', '苍石', 2238);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苏北', '苏北', 2239);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苏家屯', '苏家屯', 2240);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苏州', '苏州', 2241);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苏州北', '苏州', 2242);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苏州园区', '苏州园区', 2243);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苏州新区', '苏州新区', 2244);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苏雄', '苏雄', 2245);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苏集', '苏集', 2246);
insert into Station (Station_Name, City_Name, Station_ID)
values ('苔青', '苔青', 2247);
insert into Station (Station_Name, City_Name, Station_ID)
values ('英吉沙', '英吉沙', 2248);
insert into Station (Station_Name, City_Name, Station_ID)
values ('英德', '英德', 2249);
insert into Station (Station_Name, City_Name, Station_ID)
values ('英德西', '英德', 2250);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茂名', '茂名', 2251);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茂名东', '茂名', 2252);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茂名西', '茂名', 2253);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茂林', '茂林', 2254);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茂舍祖', '茂舍祖', 2255);
insert into Station (Station_Name, City_Name, Station_ID)
values ('范家屯', '范家屯', 2256);
insert into Station (Station_Name, City_Name, Station_ID)
values ('范镇', '范镇', 2257);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茄子溪', '茄子溪', 2258);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茅草坪', '茅草坪', 2259);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茨冲', '茨冲', 2260);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茨坝', '茨坝', 2261);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茶条沟', '茶条沟', 2262);
insert into Station (Station_Name, City_Name, Station_ID)
values ('茶陵南', '茶陵南', 2263);
insert into Station (Station_Name, City_Name, Station_ID)
values ('荆州', '荆州', 2264);
insert into Station (Station_Name, City_Name, Station_ID)
values ('荆门', '荆门', 2265);
insert into Station (Station_Name, City_Name, Station_ID)
values ('草市', '草市', 2266);
insert into Station (Station_Name, City_Name, Station_ID)
values ('草河口', '草河口', 2267);
insert into Station (Station_Name, City_Name, Station_ID)
values ('草海', '草海', 2268);
insert into Station (Station_Name, City_Name, Station_ID)
values ('荒沟西', '荒沟西', 2269);
insert into Station (Station_Name, City_Name, Station_ID)
values ('荣成', '荣成', 2270);
insert into Station (Station_Name, City_Name, Station_ID)
values ('荣昌', '荣昌', 2271);
insert into Station (Station_Name, City_Name, Station_ID)
values ('荣昌北', '荣昌', 2272);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莆田', '莆田', 2273);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莎车', '莎车', 2274);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莒南', '莒南', 2275);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莒县', '莒县', 2276);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莫尔道嘎', '莫尔道嘎', 2277);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莱芜东', '莱芜东', 2278);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莱西', '莱西', 2279);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莱西北', '莱西', 2280);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莱阳', '莱阳', 2281);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莲江口', '莲江口', 2282);
insert into Station (Station_Name, City_Name, Station_ID)
values ('莲花山', '莲花山', 2283);
insert into Station (Station_Name, City_Name, Station_ID)
values ('获嘉', '获嘉', 2284);
insert into Station (Station_Name, City_Name, Station_ID)
values ('菇园', '菇园', 2285);
insert into Station (Station_Name, City_Name, Station_ID)
values ('菏泽', '菏泽', 2286);
insert into Station (Station_Name, City_Name, Station_ID)
values ('萍乡', '萍乡', 2287);
insert into Station (Station_Name, City_Name, Station_ID)
values ('萍乡北', '萍乡', 2288);
insert into Station (Station_Name, City_Name, Station_ID)
values ('营北', '营北', 2289);
insert into Station (Station_Name, City_Name, Station_ID)
values ('营口', '营口', 2290);
insert into Station (Station_Name, City_Name, Station_ID)
values ('营口东', '营口', 2291);
insert into Station (Station_Name, City_Name, Station_ID)
values ('营城', '营城', 2292);
insert into Station (Station_Name, City_Name, Station_ID)
values ('营山', '营山', 2293);
insert into Station (Station_Name, City_Name, Station_ID)
values ('营盘水', '营盘水', 2294);
insert into Station (Station_Name, City_Name, Station_ID)
values ('营盘湾', '营盘湾', 2295);
insert into Station (Station_Name, City_Name, Station_ID)
values ('营街', '营街', 2296);
insert into Station (Station_Name, City_Name, Station_ID)
values ('萨拉齐', '萨拉齐', 2297);
insert into Station (Station_Name, City_Name, Station_ID)
values ('落坡岭', '落坡岭', 2298);
insert into Station (Station_Name, City_Name, Station_ID)
values ('落垡', '落垡', 2299);
insert into Station (Station_Name, City_Name, Station_ID)
values ('葛店南', '葛店南', 2300);
insert into Station (Station_Name, City_Name, Station_ID)
values ('葛根庙', '葛根庙', 2301);
insert into Station (Station_Name, City_Name, Station_ID)
values ('葫芦岛', '葫芦岛', 2302);
insert into Station (Station_Name, City_Name, Station_ID)
values ('葫芦岛北', '葫芦岛', 2303);
insert into Station (Station_Name, City_Name, Station_ID)
values ('葵潭', '葵潭', 2304);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蒙渡', '蒙渡', 2305);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蒙自', '蒙自', 2306);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蒙自北', '蒙自', 2307);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蒲坝', '蒲坝', 2308);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蒲城', '蒲城', 2309);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蒲城东', '蒲城', 2310);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蓝村', '蓝村', 2311);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蓟县', '蓟县', 2312);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蓬安', '蓬安', 2313);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蔡家坡', '蔡家坡', 2314);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蔡家沟', '蔡家沟', 2315);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蔡山', '蔡山', 2316);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蔺家楼', '蔺家楼', 2317);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蕲春', '蕲春', 2318);
insert into Station (Station_Name, City_Name, Station_ID)
values ('藁城', '藁城', 2319);
insert into Station (Station_Name, City_Name, Station_ID)
values ('藤县', '藤县', 2320);
insert into Station (Station_Name, City_Name, Station_ID)
values ('虎尔虎拉', '虎尔虎拉', 2321);
insert into Station (Station_Name, City_Name, Station_ID)
values ('虎山', '虎山', 2322);
insert into Station (Station_Name, City_Name, Station_ID)
values ('虎峰', '虎峰', 2323);
insert into Station (Station_Name, City_Name, Station_ID)
values ('虎林', '虎林', 2324);
insert into Station (Station_Name, City_Name, Station_ID)
values ('虎门', '虎门', 2325);
insert into Station (Station_Name, City_Name, Station_ID)
values ('虞城县', '虞城县', 2326);
insert into Station (Station_Name, City_Name, Station_ID)
values ('虢镇', '虢镇', 2327);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蚌埠', '蚌埠', 2328);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蚌埠南', '蚌埠', 2329);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蛟河', '蛟河', 2330);
insert into Station (Station_Name, City_Name, Station_ID)
values ('蛟河西', '蛟河', 2331);
insert into Station (Station_Name, City_Name, Station_ID)
values ('融安', '融安', 2332);
insert into Station (Station_Name, City_Name, Station_ID)
values ('融水', '融水', 2333);
insert into Station (Station_Name, City_Name, Station_ID)
values ('衙门庙', '衙门庙', 2334);
insert into Station (Station_Name, City_Name, Station_ID)
values ('衡山', '衡山', 2335);
insert into Station (Station_Name, City_Name, Station_ID)
values ('衡山西', '衡山', 2336);
insert into Station (Station_Name, City_Name, Station_ID)
values ('衡水', '衡水', 2337);
insert into Station (Station_Name, City_Name, Station_ID)
values ('衡阳', '衡阳', 2338);
insert into Station (Station_Name, City_Name, Station_ID)
values ('衡阳东', '衡阳', 2339);
insert into Station (Station_Name, City_Name, Station_ID)
values ('衢州', '衢州', 2340);
insert into Station (Station_Name, City_Name, Station_ID)
values ('裕国', '裕国', 2341);
insert into Station (Station_Name, City_Name, Station_ID)
values ('裴德', '裴德', 2342);
insert into Station (Station_Name, City_Name, Station_ID)
values ('褚家湾', '褚家湾', 2343);
insert into Station (Station_Name, City_Name, Station_ID)
values ('襄垣', '襄垣', 2344);
insert into Station (Station_Name, City_Name, Station_ID)
values ('襄汾', '襄汾', 2345);
insert into Station (Station_Name, City_Name, Station_ID)
values ('襄汾西', '襄汾', 2346);
insert into Station (Station_Name, City_Name, Station_ID)
values ('襄河', '襄河', 2347);
insert into Station (Station_Name, City_Name, Station_ID)
values ('襄阳', '襄阳', 2348);
insert into Station (Station_Name, City_Name, Station_ID)
values ('襄阳东', '襄阳', 2349);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西丰', '西丰', 2350);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西乌旗', '西乌旗', 2351);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西乡', '西乡', 2352);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西六方', '西六方', 2353);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西哲里木', '西哲里木', 2354);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西固城', '西固城', 2355);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西大庙', '西大庙', 2356);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西宁', '西宁', 2357);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西安', '西安', 2358);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西安北', '西安', 2359);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西安南', '西安', 2360);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西小召', '西小召', 2361);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西岗子', '西岗子', 2362);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西岭口', '西岭口', 2363);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西峡', '西峡', 2364);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西平', '西平', 2365);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西斗铺', '西斗铺', 2366);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西昌', '西昌', 2367);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西昌南', '西昌', 2368);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西林', '西林', 2369);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西柳', '西柳', 2370);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西武匠', '西武匠', 2371);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西湖东', '西湖东', 2372);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西胡尔清', '西胡尔清', 2373);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西街口', '西街口', 2374);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西里', '西里', 2375);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西阳岔', '西阳岔', 2376);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西阳村', '西阳村', 2377);
insert into Station (Station_Name, City_Name, Station_ID)
values ('西麻山', '西麻山', 2378);
insert into Station (Station_Name, City_Name, Station_ID)
values ('角美', '角美', 2379);
insert into Station (Station_Name, City_Name, Station_ID)
values ('讷尔克气', '讷尔克气', 2380);
insert into Station (Station_Name, City_Name, Station_ID)
values ('讷河', '讷河', 2381);
insert into Station (Station_Name, City_Name, Station_ID)
values ('许三湾', '许三湾', 2382);
insert into Station (Station_Name, City_Name, Station_ID)
values ('许家台', '许家台', 2383);
insert into Station (Station_Name, City_Name, Station_ID)
values ('许家屯', '许家屯', 2384);
insert into Station (Station_Name, City_Name, Station_ID)
values ('许昌', '许昌', 2385);
insert into Station (Station_Name, City_Name, Station_ID)
values ('许昌东', '许昌', 2386);
insert into Station (Station_Name, City_Name, Station_ID)
values ('诏安', '诏安', 2387);
insert into Station (Station_Name, City_Name, Station_ID)
values ('诸城', '诸城', 2388);
insert into Station (Station_Name, City_Name, Station_ID)
values ('诸暨', '诸暨', 2389);
insert into Station (Station_Name, City_Name, Station_ID)
values ('谢家镇', '谢家镇', 2390);
insert into Station (Station_Name, City_Name, Station_ID)
values ('谷城', '谷城', 2391);
insert into Station (Station_Name, City_Name, Station_ID)
values ('豆庄', '豆庄', 2392);
insert into Station (Station_Name, City_Name, Station_ID)
values ('豆张庄', '豆张庄', 2393);
insert into Station (Station_Name, City_Name, Station_ID)
values ('豆沙关', '豆沙关', 2394);
insert into Station (Station_Name, City_Name, Station_ID)
values ('豆罗', '豆罗', 2395);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贲红', '贲红', 2396);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贵定', '贵定', 2397);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贵定北', '贵定', 2398);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贵定南', '贵定', 2399);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贵定县', '贵定县', 2400);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贵港', '贵港', 2401);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贵溪', '贵溪', 2402);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贵阳', '贵阳', 2403);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贵阳北', '贵阳', 2404);
insert into Station (Station_Name, City_Name, Station_ID)
values ('费县', '费县', 2405);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贺家店', '贺家店', 2406);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贺州', '贺州', 2407);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贺日斯台', '贺日斯台', 2408);
insert into Station (Station_Name, City_Name, Station_ID)
values ('贺胜桥东', '贺胜桥东', 2409);
insert into Station (Station_Name, City_Name, Station_ID)
values ('资中', '资中', 2410);
insert into Station (Station_Name, City_Name, Station_ID)
values ('资中北', '资中', 2411);
insert into Station (Station_Name, City_Name, Station_ID)
values ('资溪', '资溪', 2412);
insert into Station (Station_Name, City_Name, Station_ID)
values ('资阳', '资阳', 2413);
insert into Station (Station_Name, City_Name, Station_ID)
values ('资阳北', '资阳', 2414);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赛乌苏', '赛乌苏', 2415);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赛汗塔拉', '赛汗塔拉', 2416);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赣州', '赣州', 2417);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赤壁', '赤壁', 2418);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赤壁北', '赤壁', 2419);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赤峰', '赤峰', 2420);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赤峰东', '赤峰', 2421);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赤峰西', '赤峰', 2422);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赫尔洪得', '赫尔洪得', 2423);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赵光', '赵光', 2424);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赵城', '赵城', 2425);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赵庄', '赵庄', 2426);
insert into Station (Station_Name, City_Name, Station_ID)
values ('赶水', '赶水', 2427);
insert into Station (Station_Name, City_Name, Station_ID)
values ('超梁沟', '超梁沟', 2428);
insert into Station (Station_Name, City_Name, Station_ID)
values ('越西', '越西', 2429);
insert into Station (Station_Name, City_Name, Station_ID)
values ('路口铺', '路口铺', 2430);
insert into Station (Station_Name, City_Name, Station_ID)
values ('车转湾', '车转湾', 2431);
insert into Station (Station_Name, City_Name, Station_ID)
values ('轩岗', '轩岗', 2432);
insert into Station (Station_Name, City_Name, Station_ID)
values ('轮台', '轮台', 2433);
insert into Station (Station_Name, City_Name, Station_ID)
values ('轵城', '轵城', 2434);
insert into Station (Station_Name, City_Name, Station_ID)
values ('轸溪', '轸溪', 2435);
insert into Station (Station_Name, City_Name, Station_ID)
values ('辛集', '辛集', 2436);
insert into Station (Station_Name, City_Name, Station_ID)
values ('辰清', '辰清', 2437);
insert into Station (Station_Name, City_Name, Station_ID)
values ('辰溪', '辰溪', 2438);
insert into Station (Station_Name, City_Name, Station_ID)
values ('边沟', '边沟', 2439);
insert into Station (Station_Name, City_Name, Station_ID)
values ('辽中', '辽中', 2440);
insert into Station (Station_Name, City_Name, Station_ID)
values ('辽源', '辽源', 2441);
insert into Station (Station_Name, City_Name, Station_ID)
values ('辽阳', '辽阳', 2442);
insert into Station (Station_Name, City_Name, Station_ID)
values ('达家沟', '达家沟', 2443);
insert into Station (Station_Name, City_Name, Station_ID)
values ('达州', '达州', 2444);
insert into Station (Station_Name, City_Name, Station_ID)
values ('达拉滨', '达拉滨', 2445);
insert into Station (Station_Name, City_Name, Station_ID)
values ('达拉特西', '达拉特西', 2446);
insert into Station (Station_Name, City_Name, Station_ID)
values ('达日其嘎', '达日其嘎', 2447);
insert into Station (Station_Name, City_Name, Station_ID)
values ('迁安', '迁安', 2448);
insert into Station (Station_Name, City_Name, Station_ID)
values ('迎宾路', '迎宾路', 2449);
insert into Station (Station_Name, City_Name, Station_ID)
values ('迎春', '迎春', 2450);
insert into Station (Station_Name, City_Name, Station_ID)
values ('迎祥街', '迎祥街', 2451);
insert into Station (Station_Name, City_Name, Station_ID)
values ('运城', '运城', 2452);
insert into Station (Station_Name, City_Name, Station_ID)
values ('运城北', '运城', 2453);
insert into Station (Station_Name, City_Name, Station_ID)
values ('进贤', '进贤', 2454);
insert into Station (Station_Name, City_Name, Station_ID)
values ('进贤南', '进贤', 2455);
insert into Station (Station_Name, City_Name, Station_ID)
values ('连云港东', '连云港东', 2456);
insert into Station (Station_Name, City_Name, Station_ID)
values ('连山关', '连山关', 2457);
insert into Station (Station_Name, City_Name, Station_ID)
values ('连江', '连江', 2458);
insert into Station (Station_Name, City_Name, Station_ID)
values ('连珠山', '连珠山', 2459);
insert into Station (Station_Name, City_Name, Station_ID)
values ('迤资', '迤资', 2460);
insert into Station (Station_Name, City_Name, Station_ID)
values ('迤那', '迤那', 2461);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通化', '通化', 2462);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通化县', '通化县', 2463);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通北', '通北', 2464);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通天屯', '通天屯', 2465);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通安驿', '通安驿', 2466);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通州西', '通州西', 2467);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通海', '通海', 2468);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通辽', '通辽', 2469);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通远堡', '通远堡', 2470);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通远堡西', '通远堡', 2471);
insert into Station (Station_Name, City_Name, Station_ID)
values ('通道', '通道', 2472);
insert into Station (Station_Name, City_Name, Station_ID)
values ('遂宁', '遂宁', 2473);
insert into Station (Station_Name, City_Name, Station_ID)
values ('遂平', '遂平', 2474);
insert into Station (Station_Name, City_Name, Station_ID)
values ('遂溪', '遂溪', 2475);
insert into Station (Station_Name, City_Name, Station_ID)
values ('道仑郭勒', '道仑郭勒', 2476);
insert into Station (Station_Name, City_Name, Station_ID)
values ('道州', '道州', 2477);
insert into Station (Station_Name, City_Name, Station_ID)
values ('道德', '道德', 2478);
insert into Station (Station_Name, City_Name, Station_ID)
values ('道清', '道清', 2479);
insert into Station (Station_Name, City_Name, Station_ID)
values ('遵义', '遵义', 2480);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邓家湾', '邓家湾', 2481);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邓州', '邓州', 2482);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邢台', '邢台', 2483);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邢台东', '邢台', 2484);
insert into Station (Station_Name, City_Name, Station_ID)
values ('那曲', '那曲', 2485);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邯郸', '邯郸', 2486);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邯郸东', '邯郸', 2487);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邳州', '邳州', 2488);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邵东', '邵东', 2489);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邵家堂', '邵家堂', 2490);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邵武', '邵武', 2491);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邵阳', '邵阳', 2492);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邵阳北', '邵阳', 2493);
insert into Station (Station_Name, City_Name, Station_ID)
values ('邹城', '邹城', 2494);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郁南', '郁南', 2495);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郁山', '郁山', 2496);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郑州', '郑州', 2497);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郑州东', '郑州', 2498);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郓城', '郓城', 2499);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郫县', '郫县', 2500);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郫县西', '郫县', 2501);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郭家屯', '郭家屯', 2502);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郭家店', '郭家店', 2503);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郭尔奔敖包', '郭尔奔敖包', 2504);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郯城', '郯城', 2505);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郴州', '郴州', 2506);
insert into Station (Station_Name, City_Name, Station_ID)
values ('郴州西', '郴州', 2507);
insert into Station (Station_Name, City_Name, Station_ID)
values ('都匀', '都匀', 2508);
insert into Station (Station_Name, City_Name, Station_ID)
values ('都匀东', '都匀', 2509);
insert into Station (Station_Name, City_Name, Station_ID)
values ('都格', '都格', 2510);
insert into Station (Station_Name, City_Name, Station_ID)
values ('都江堰', '都江堰', 2511);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鄂尔多斯', '鄂尔多斯', 2512);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鄂州', '鄂州', 2513);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鄄城', '鄄城', 2514);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鄯善', '鄯善', 2515);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鄯善北', '鄯善', 2516);
insert into Station (Station_Name, City_Name, Station_ID)
values ('酉阳', '酉阳', 2517);
insert into Station (Station_Name, City_Name, Station_ID)
values ('酒泉', '酒泉', 2518);
insert into Station (Station_Name, City_Name, Station_ID)
values ('酒泉南', '酒泉', 2519);
insert into Station (Station_Name, City_Name, Station_ID)
values ('醴陵', '醴陵', 2520);
insert into Station (Station_Name, City_Name, Station_ID)
values ('醴陵东', '醴陵', 2521);
insert into Station (Station_Name, City_Name, Station_ID)
values ('里木店', '里木店', 2522);
insert into Station (Station_Name, City_Name, Station_ID)
values ('重庆', '重庆', 2523);
insert into Station (Station_Name, City_Name, Station_ID)
values ('重庆北', '重庆', 2524);
insert into Station (Station_Name, City_Name, Station_ID)
values ('重庆南', '重庆', 2525);
insert into Station (Station_Name, City_Name, Station_ID)
values ('野三坡', '野三坡', 2526);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金刚沱', '金刚沱', 2527);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金华', '金华', 2528);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金华南', '金华', 2529);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金口河', '金口河', 2530);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金坑', '金坑', 2531);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金城江', '金城江', 2532);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金宝屯', '金宝屯', 2533);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金家店', '金家店', 2534);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金寨', '金寨', 2535);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金山北', '金山北', 2536);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金山屯', '金山屯', 2537);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金州', '金州', 2538);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金昌', '金昌', 2539);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金杖子', '金杖子', 2540);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金沟屯', '金沟屯', 2541);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金河', '金河', 2542);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金银川', '金银川', 2543);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金马村', '金马村', 2544);
insert into Station (Station_Name, City_Name, Station_ID)
values ('金鸡村', '金鸡村', 2545);
insert into Station (Station_Name, City_Name, Station_ID)
values ('钟家村', '钟家村', 2546);
insert into Station (Station_Name, City_Name, Station_ID)
values ('钟山西', '钟山西', 2547);
insert into Station (Station_Name, City_Name, Station_ID)
values ('钟祥', '钟祥', 2548);
insert into Station (Station_Name, City_Name, Station_ID)
values ('钦州东', '钦州东', 2549);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铁佛寺', '铁佛寺', 2550);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铁力', '铁力', 2551);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铁厂', '铁厂', 2552);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铁口', '铁口', 2553);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铁岭', '铁岭', 2554);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铁岭西', '铁岭', 2555);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铁西', '铁西', 2556);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铜仁', '铜仁', 2557);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铜仁南', '铜仁', 2558);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铜罐驿', '铜罐驿', 2559);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铜陵', '铜陵', 2560);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铜陵北', '铜陵', 2561);
insert into Station (Station_Name, City_Name, Station_ID)
values ('铜鼓溪', '铜鼓溪', 2562);
insert into Station (Station_Name, City_Name, Station_ID)
values ('银川', '银川', 2563);
insert into Station (Station_Name, City_Name, Station_ID)
values ('银川南', '银川', 2564);
insert into Station (Station_Name, City_Name, Station_ID)
values ('银浪', '银浪', 2565);
insert into Station (Station_Name, City_Name, Station_ID)
values ('银滩', '银滩', 2566);
insert into Station (Station_Name, City_Name, Station_ID)
values ('银瓶', '银瓶', 2567);
insert into Station (Station_Name, City_Name, Station_ID)
values ('银镇', '银镇', 2568);
insert into Station (Station_Name, City_Name, Station_ID)
values ('锡林呼都嘎', '锡林呼都嘎', 2569);
insert into Station (Station_Name, City_Name, Station_ID)
values ('锡林浩特', '锡林浩特', 2570);
insert into Station (Station_Name, City_Name, Station_ID)
values ('锡铁山', '锡铁山', 2571);
insert into Station (Station_Name, City_Name, Station_ID)
values ('锦州', '锦州', 2572);
insert into Station (Station_Name, City_Name, Station_ID)
values ('锦州南', '锦州', 2573);
insert into Station (Station_Name, City_Name, Station_ID)
values ('锦河', '锦河', 2574);
insert into Station (Station_Name, City_Name, Station_ID)
values ('镇城底', '镇城底', 2575);
insert into Station (Station_Name, City_Name, Station_ID)
values ('镇安', '镇安', 2576);
insert into Station (Station_Name, City_Name, Station_ID)
values ('镇平', '镇平', 2577);
insert into Station (Station_Name, City_Name, Station_ID)
values ('镇江', '镇江', 2578);
insert into Station (Station_Name, City_Name, Station_ID)
values ('镇江南', '镇江', 2579);
insert into Station (Station_Name, City_Name, Station_ID)
values ('镇紫街', '镇紫街', 2580);
insert into Station (Station_Name, City_Name, Station_ID)
values ('镇赉', '镇赉', 2581);
insert into Station (Station_Name, City_Name, Station_ID)
values ('镇远', '镇远', 2582);
insert into Station (Station_Name, City_Name, Station_ID)
values ('镜铁山', '镜铁山', 2583);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长临河', '长临河', 2584);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长兴', '长兴', 2585);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长兴南', '长兴', 2586);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长农', '长农', 2587);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长冲', '长冲', 2588);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长发屯', '长发屯', 2589);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长坡岭', '长坡岭', 2590);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长垣', '长垣', 2591);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长城', '长城', 2592);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长子', '长子', 2593);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长寿', '长寿', 2594);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长寿北', '长寿', 2595);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长山屯', '长山屯', 2596);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长庆桥', '长庆桥', 2597);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长征', '长征', 2598);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长春', '长春', 2599);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长春西', '长春', 2600);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长武', '长武', 2601);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长汀南', '长汀南', 2602);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长汀镇', '长汀镇', 2603);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长沙', '长沙', 2604);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长沙南', '长沙', 2605);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长河碥', '长河碥', 2606);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长治', '长治', 2607);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长治北', '长治', 2608);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长潭沟', '长潭沟', 2609);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长甸', '长甸', 2610);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长葛', '长葛', 2611);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长虹', '长虹', 2612);
insert into Station (Station_Name, City_Name, Station_ID)
values ('长阳', '长阳', 2613);
insert into Station (Station_Name, City_Name, Station_ID)
values ('门源', '门源', 2614);
insert into Station (Station_Name, City_Name, Station_ID)
values ('门达', '门达', 2615);
insert into Station (Station_Name, City_Name, Station_ID)
values ('闹海营', '闹海营', 2616);
insert into Station (Station_Name, City_Name, Station_ID)
values ('闻喜', '闻喜', 2617);
insert into Station (Station_Name, City_Name, Station_ID)
values ('闻喜西', '闻喜', 2618);
insert into Station (Station_Name, City_Name, Station_ID)
values ('闽清北', '闽清北', 2619);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阆中', '阆中', 2620);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阎家', '阎家', 2621);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阎良', '阎良', 2622);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阜南', '阜南', 2623);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阜宁', '阜宁', 2624);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阜新', '阜新', 2625);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阜阳', '阜阳', 2626);
insert into Station (Station_Name, City_Name, Station_ID)
values ('防城港北', '防城港北', 2627);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳信', '阳信', 2628);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳城', '阳城', 2629);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳岔', '阳岔', 2630);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳平关', '阳平关', 2631);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳新', '阳新', 2632);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳明堡', '阳明堡', 2633);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳春', '阳春', 2634);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳曲', '阳曲', 2635);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳朔', '阳朔', 2636);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳泉', '阳泉', 2637);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳泉北', '阳泉', 2638);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳泉曲', '阳泉曲', 2639);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳澄湖', '阳澄湖', 2640);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳谷', '阳谷', 2641);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳邑', '阳邑', 2642);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阳高', '阳高', 2643);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿乌尼', '阿乌尼', 2644);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿克苏', '阿克苏', 2645);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿克陶', '阿克陶', 2646);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿南庄', '阿南庄', 2647);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿图什', '阿图什', 2648);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿城', '阿城', 2649);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿寨', '阿寨', 2650);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿尔山', '阿尔山', 2651);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿尔山北', '阿尔山北', 2652);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿拉山口', '阿拉山口', 2653);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿木尔', '阿木尔', 2654);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿贵图', '阿贵图', 2655);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿里河', '阿里河', 2656);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿金', '阿金', 2657);
insert into Station (Station_Name, City_Name, Station_ID)
values ('阿龙山', '阿龙山', 2658);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陆丰', '陆丰', 2659);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陆川', '陆川', 2660);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陆良', '陆良', 2661);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陇县', '陇县', 2662);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陇西', '陇西', 2663);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陈官营', '陈官营', 2664);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陈相屯', '陈相屯', 2665);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陵水', '陵水', 2666);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陶家屯', '陶家屯', 2667);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陶思浩', '陶思浩', 2668);
insert into Station (Station_Name, City_Name, Station_ID)
values ('陶赖昭', '陶赖昭', 2669);
insert into Station (Station_Name, City_Name, Station_ID)
values ('隆化', '隆化', 2670);
insert into Station (Station_Name, City_Name, Station_ID)
values ('隆安东', '隆安东', 2671);
insert into Station (Station_Name, City_Name, Station_ID)
values ('隆昌', '隆昌', 2672);
insert into Station (Station_Name, City_Name, Station_ID)
values ('隆昌北', '隆昌', 2673);
insert into Station (Station_Name, City_Name, Station_ID)
values ('随州', '随州', 2674);
insert into Station (Station_Name, City_Name, Station_ID)
values ('雁荡山', '雁荡山', 2675);
insert into Station (Station_Name, City_Name, Station_ID)
values ('雅河', '雅河', 2676);
insert into Station (Station_Name, City_Name, Station_ID)
values ('雅鲁', '雅鲁', 2677);
insert into Station (Station_Name, City_Name, Station_ID)
values ('集宁南', '集宁南', 2678);
insert into Station (Station_Name, City_Name, Station_ID)
values ('集安', '集安', 2679);
insert into Station (Station_Name, City_Name, Station_ID)
values ('雨格', '雨格', 2680);
insert into Station (Station_Name, City_Name, Station_ID)
values ('零陵', '零陵', 2681);
insert into Station (Station_Name, City_Name, Station_ID)
values ('雷州', '雷州', 2682);
insert into Station (Station_Name, City_Name, Station_ID)
values ('霍尔果斯', '霍尔果斯', 2683);
insert into Station (Station_Name, City_Name, Station_ID)
values ('霍州', '霍州', 2684);
insert into Station (Station_Name, City_Name, Station_ID)
values ('霍州东', '霍州', 2685);
insert into Station (Station_Name, City_Name, Station_ID)
values ('霍林郭勒', '霍林郭勒', 2686);
insert into Station (Station_Name, City_Name, Station_ID)
values ('霍邱', '霍邱', 2687);
insert into Station (Station_Name, City_Name, Station_ID)
values ('霞浦', '霞浦', 2688);
insert into Station (Station_Name, City_Name, Station_ID)
values ('露水河', '露水河', 2689);
insert into Station (Station_Name, City_Name, Station_ID)
values ('霸州', '霸州', 2690);
insert into Station (Station_Name, City_Name, Station_ID)
values ('霸州西', '霸州', 2691);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青县', '青县', 2692);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青城山', '青城山', 2693);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青堆', '青堆', 2694);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青山', '青山', 2695);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青岛', '青岛', 2696);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青岛北', '青岛', 2697);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青岭子', '青岭子', 2698);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青州市', '青州市', 2699);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青水山', '青水山', 2700);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青沟子', '青沟子', 2701);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青溪', '青溪', 2702);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青田', '青田', 2703);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青白江东', '青白江东', 2704);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青神', '青神', 2705);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青莲', '青莲', 2706);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青铜峡', '青铜峡', 2707);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青龙', '青龙', 2708);
insert into Station (Station_Name, City_Name, Station_ID)
values ('青龙山', '青龙山', 2709);
insert into Station (Station_Name, City_Name, Station_ID)
values ('靖宇', '靖宇', 2710);
insert into Station (Station_Name, City_Name, Station_ID)
values ('靖州', '靖州', 2711);
insert into Station (Station_Name, City_Name, Station_ID)
values ('靖西', '靖西', 2712);
insert into Station (Station_Name, City_Name, Station_ID)
values ('靖边', '靖边', 2713);
insert into Station (Station_Name, City_Name, Station_ID)
values ('靖远', '靖远', 2714);
insert into Station (Station_Name, City_Name, Station_ID)
values ('靖远西', '靖远', 2715);
insert into Station (Station_Name, City_Name, Station_ID)
values ('静海', '静海', 2716);
insert into Station (Station_Name, City_Name, Station_ID)
values ('革居', '革居', 2717);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鞍山', '鞍山', 2718);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鞍山西', '鞍山', 2719);
insert into Station (Station_Name, City_Name, Station_ID)
values ('韦庄', '韦庄', 2720);
insert into Station (Station_Name, City_Name, Station_ID)
values ('韩城', '韩城', 2721);
insert into Station (Station_Name, City_Name, Station_ID)
values ('韩府湾', '韩府湾', 2722);
insert into Station (Station_Name, City_Name, Station_ID)
values ('韩麻营', '韩麻营', 2723);
insert into Station (Station_Name, City_Name, Station_ID)
values ('韶关', '韶关', 2724);
insert into Station (Station_Name, City_Name, Station_ID)
values ('韶关东', '韶关', 2725);
insert into Station (Station_Name, City_Name, Station_ID)
values ('韶山', '韶山', 2726);
insert into Station (Station_Name, City_Name, Station_ID)
values ('韶山南', '韶山', 2727);
insert into Station (Station_Name, City_Name, Station_ID)
values ('项城', '项城', 2728);
insert into Station (Station_Name, City_Name, Station_ID)
values ('顺义', '顺义', 2729);
insert into Station (Station_Name, City_Name, Station_ID)
values ('顺德', '顺德', 2730);
insert into Station (Station_Name, City_Name, Station_ID)
values ('顺德学院', '顺德学院', 2731);
insert into Station (Station_Name, City_Name, Station_ID)
values ('顺昌', '顺昌', 2732);
insert into Station (Station_Name, City_Name, Station_ID)
values ('额济纳', '额济纳', 2733);
insert into Station (Station_Name, City_Name, Station_ID)
values ('风水沟', '风水沟', 2734);
insert into Station (Station_Name, City_Name, Station_ID)
values ('风陵渡', '风陵渡', 2735);
insert into Station (Station_Name, City_Name, Station_ID)
values ('饶平', '饶平', 2736);
insert into Station (Station_Name, City_Name, Station_ID)
values ('饶阳', '饶阳', 2737);
insert into Station (Station_Name, City_Name, Station_ID)
values ('香兰', '香兰', 2738);
insert into Station (Station_Name, City_Name, Station_ID)
values ('香坊', '香坊', 2739);
insert into Station (Station_Name, City_Name, Station_ID)
values ('马三家', '马三家', 2740);
insert into Station (Station_Name, City_Name, Station_ID)
values ('马兰', '马兰', 2741);
insert into Station (Station_Name, City_Name, Station_ID)
values ('马林', '马林', 2742);
insert into Station (Station_Name, City_Name, Station_ID)
values ('马架子', '马架子', 2743);
insert into Station (Station_Name, City_Name, Station_ID)
values ('马盖图', '马盖图', 2744);
insert into Station (Station_Name, City_Name, Station_ID)
values ('马莲河', '马莲河', 2745);
insert into Station (Station_Name, City_Name, Station_ID)
values ('马鞍山', '马鞍山', 2746);
insert into Station (Station_Name, City_Name, Station_ID)
values ('马鞍山东', '马鞍山', 2747);
insert into Station (Station_Name, City_Name, Station_ID)
values ('马龙', '马龙', 2748);
insert into Station (Station_Name, City_Name, Station_ID)
values ('驻马店', '驻马店', 2749);
insert into Station (Station_Name, City_Name, Station_ID)
values ('驻马店西', '驻马店', 2750);
insert into Station (Station_Name, City_Name, Station_ID)
values ('驼腰岭', '驼腰岭', 2751);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高台', '高台', 2752);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高台南', '高台', 2753);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高台子', '高台子', 2754);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高各庄', '高各庄', 2755);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高头', '高头', 2756);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高安', '高安', 2757);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高家', '高家', 2758);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高家村', '高家村', 2759);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高密', '高密', 2760);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高山子', '高山子', 2761);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高峰', '高峰', 2762);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高州', '高州', 2763);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高平', '高平', 2764);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高村', '高村', 2765);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高林屯', '高林屯', 2766);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高桥镇', '高桥镇', 2767);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高滩', '高滩', 2768);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高碑店', '高碑店', 2769);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高碑店东', '高碑店', 2770);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高谷', '高谷', 2771);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高邑', '高邑', 2772);
insert into Station (Station_Name, City_Name, Station_ID)
values ('高邑西', '高邑', 2773);
insert into Station (Station_Name, City_Name, Station_ID)
values ('魏善庄', '魏善庄', 2774);
insert into Station (Station_Name, City_Name, Station_ID)
values ('魏杖子', '魏杖子', 2775);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鱼儿沟', '鱼儿沟', 2776);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鱼泉', '鱼泉', 2777);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鲁山', '鲁山', 2778);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鲁河', '鲁河', 2779);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鲁番', '鲁番', 2780);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鲅鱼圈', '鲅鱼圈', 2781);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鲘门', '鲘门', 2782);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鳌江', '鳌江', 2783);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鸡东', '鸡东', 2784);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鸡冠山', '鸡冠山', 2785);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鸡西', '鸡西', 2786);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鸭园', '鸭园', 2787);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鸳鸯镇', '鸳鸯镇', 2788);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鸽子洞', '鸽子洞', 2789);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹤北', '鹤北', 2790);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹤壁', '鹤壁', 2791);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹤壁东', '鹤壁', 2792);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹤山', '鹤山', 2793);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹤岗', '鹤岗', 2794);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹤庆', '鹤庆', 2795);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹤立', '鹤立', 2796);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹰手营子', '鹰手营子', 2797);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹰潭', '鹰潭', 2798);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹰潭北', '鹰潭', 2799);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹿寨', '鹿寨', 2800);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹿寨北', '鹿寨', 2801);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鹿道', '鹿道', 2802);
insert into Station (Station_Name, City_Name, Station_ID)
values ('麻城', '麻城', 2803);
insert into Station (Station_Name, City_Name, Station_ID)
values ('麻城北', '麻城', 2804);
insert into Station (Station_Name, City_Name, Station_ID)
values ('麻尾', '麻尾', 2805);
insert into Station (Station_Name, City_Name, Station_ID)
values ('麻山', '麻山', 2806);
insert into Station (Station_Name, City_Name, Station_ID)
values ('麻柳', '麻柳', 2807);
insert into Station (Station_Name, City_Name, Station_ID)
values ('麻阳', '麻阳', 2808);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄', '黄', 2809);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄口', '黄口', 2810);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄家店', '黄家店', 2811);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄山', '黄山', 2812);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄山北', '黄山北', 2813);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄州', '黄州', 2814);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄平', '黄平', 2815);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄村', '黄村', 2816);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄松甸', '黄松甸', 2817);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄柏', '黄柏', 2818);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄梅', '黄梅', 2819);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄河景区', '黄河景区', 2820);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄泥崴子', '黄泥崴子', 2821);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄泥河', '黄泥河', 2822);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄津', '黄津', 2823);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄流', '黄流', 2824);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄瓜园', '黄瓜园', 2825);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄石', '黄石', 2826);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄石北', '黄石', 2827);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄羊湾', '黄羊湾', 2828);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄羊滩', '黄羊滩', 2829);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄羊镇', '黄羊镇', 2830);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄花筒', '黄花筒', 2831);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄陵', '黄陵', 2832);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黄陵南', '黄陵', 2833);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黎城', '黎城', 2834);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黎塘', '黎塘', 2835);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黑井', '黑井', 2836);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黑冲滩', '黑冲滩', 2837);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黑台', '黑台', 2838);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黑旺', '黑旺', 2839);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黑水', '黑水', 2840);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黑河', '黑河', 2841);
insert into Station (Station_Name, City_Name, Station_ID)
values ('黔江', '黔江', 2842);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鼎湖东', '鼎湖东', 2843);
insert into Station (Station_Name, City_Name, Station_ID)
values ('鼎湖山', '鼎湖山', 2844);
insert into Station (Station_Name, City_Name, Station_ID)
values ('齐哈日格图', '齐哈日格图', 2845);
insert into Station (Station_Name, City_Name, Station_ID)
values ('齐齐哈尔', '齐齐哈尔', 2846);
insert into Station (Station_Name, City_Name, Station_ID)
values ('齐齐哈尔南', '齐齐哈尔', 2847);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙丰', '龙丰', 2848);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙井', '龙井', 2849);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙伯屯', '龙伯屯', 2850);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙华', '龙华', 2851);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙南', '龙南', 2852);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙嘉', '龙嘉', 2853);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙塘坝', '龙塘坝', 2854);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙山镇', '龙山镇', 2855);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙岩', '龙岩', 2856);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙川', '龙川', 2857);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙市', '龙市', 2858);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙江', '龙江', 2859);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙池', '龙池', 2860);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙沟', '龙沟', 2861);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙泉寺', '龙泉寺', 2862);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙洞堡', '龙洞堡', 2863);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙游', '龙游', 2864);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙爪沟', '龙爪沟', 2865);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙船', '龙船', 2866);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙里北', '龙里北', 2867);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙镇', '龙镇', 2868);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙门河', '龙门河', 2869);
insert into Station (Station_Name, City_Name, Station_ID)
values ('龙骨甸', '龙骨甸', 2870);
