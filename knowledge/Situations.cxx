#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

// Start PolName
PolName -> Word<kwtype=pol>;
// End PolName

// Start med
hospitalW -> 'врач'|'доктор'|'лечение'|'госпиталь'|'больница'|'поликлиника'|'диета';
PP -> Prep hospitalW;
med -> Verb PP;
// End med

// Start WeightZn
WeightW -> 'сантиметр'|'килограмм';
WeightSokr -> 'см'|'кг';
Weight -> 'вес';
Count -> AnyWord<wff=/[1-9]?[0-9]?[0-9]/>;
WeightZn -> Count WeightW;
WeightZn -> Count WeightSokr;
WeightZn -> AnyWord Count WeightW;
WeightZn -> AnyWord Count WeightSokr;
WeightZn -> Adj Weight;
// End WeightZn

// Start Age
AgeW-> 'год'|'лет';
AgeNum -> AnyWord<wff=/[1-9]?[0-9]-?((ый)|(ть)|(ой))?/>;

Age -> AgeNum AgeW;
// End Age

// Start Picture
Video -> 'видео'|'съёмка'|'фотография'|'фото';
VideoV -> 'снимать'|'фотографировать'|'поснимать'| 'пофотографировать';
Picture -> Prep Video|Verb Video|VideoV Noun|Verb VideoV;
// End Picture

// Start Fines
Fine -> 'штраф';
FineVerb -> 'штрафовать'|'оштрафовать'|'заплатить';
//размер штрафа
Count -> AnyWord<wff=/[1-9]?[0-9]?[0-9]/>;
Currency -> 'иена';
CountZn -> Count Currency;
CountZnach -> Prep CountZn;
Fines -> Verb Fine;
Fines -> FineVerb CountZn;
Fines -> FineVerb;
Fines -> Verb CountZnach;
Fines -> Verb CountZn;
// End Fines

// Start Kvadrocopter
kvadro -> 'квадрокоптер';
Kvadrocopter -> Prep kvadro | Verb kvadro | kvadro;
// End Kvadrocopter

// Start location
locationWord -> 'кафе'|'кинотеатр'|'метро'|'спортзал'|'площадь'|'парк'|'ресторан'|'библиотека'|'магазин'|'супермарк ет'|'автобус'|'музей'|'галлерея'|'выставка'|'столовая'|'кофейня'|'суши-бар'|'работа';
location -> Prep locationWord;
// End location

// Start CultureAction
actionVerb-> 'сморкаться'|'высморкаться';
actionWord -> 'платок'|'салфетка'|'насморк';
CultureAction -> Verb actionVerb|Verb actionWord| actionVerb Prep actionWord| actionVerb; //реакция окружающих
// End CultureAction

// Start reaction
reactionWord -> 'смотреть'|'шептаться'|'ругаться'|'кричать'|'закричать'|'накричать'|'замечание' | 'выгнать';
reaction -> Verb reactionWord|Adv reactionWord|reactionWord;
// End reaction

// Start garbage
garbageWord -> 'сор'|'мусор'|'отходы';
garbageVerb -> 'выкинуть'|'выбросить'|'утилизировать';
garbage -> garbageVerb garbageWord| garbageVerb Noun| garbageWord; //место для выброса мусора
// End garbage

// Start urn
urnNegative -> 'не';
urnVerbNegative -> 'нет'|'отсутствовать'|urnNegative Verb;
urnWord -> 'бак'|'урна'|'контейнер';
urn -> urnVerbNegative urnWord|urnVerbNegative urnWord Prep garbageWord|
urnVerbNegative Adj urnWord| urnWord urnVerbNegative|urnWord Prep garbageWord urnVerbNegative| Adj urnWord urnVerbNegative|Adj urnWord| urnWord;
// End urn

// Start tips
Count -> AnyWord<wff=/[1-9]?[0-9]?[0-9]/>;
moneyWord -> 'деньги'|'чаевые'|'иена'|'чай';
tipsWord -> 'положить'|'оставить'|'дать';
tips -> tipsWord moneyWord| tipsWord Count moneyWord|tipsWord Prep moneyWord; //заслуга заведения
// End tips

// Start foodAction
foodActionAdj -> 'хороший'|'вкусный'|'быстрый';
foodActionWord -> 'еда'|'обслуживание'|'атмосфера';
foodAction -> foodActionAdj foodActionWord| Adj foodActionWord| foodActionAdj Noun;
// End foodAction

// Start tattoo
tattooVerb -> 'изобразить'|'изображать'|'набить'|'наколоть';
tattoo -> 'тату'|'татуировка'| tattooVerb Noun;
// End tattoo

// Start getNameAction
getNameActionWord -> 'имя';
getNameActionVerb -> 'назвать'|'звать';
getNameActionVerbName -> 'дать';
getNameAction -> getNameActionVerbName getNameActionWord|getNameActionWord|getNameActionVerb; //родство
// End getNameAction

// Start kinship
kinship ->
'сын'|'дочь'|'малыш'|'племянник'|'племянница'|'сестра'|'брат'|'ребёнок'|'дочка'|'сынок'; //Имя
// End kinship

// Start name
name -> AnyWord<gram="имя">;
// End name

// Start PersonalSpace
PersonalSpaceVerb -> 'слушать'|'говорить'|'трогать'|'толкать'|'лезть'|'ругаться'|'скандалить'|'спорить'|'целоваться';
PersonalSpace -> PersonalSpaceVerb Prep Noun|Adv PersonalSpaceVerb| PersonalSpaceVerb Noun| PersonalSpaceVerb;
// End PersonalSpace

// Start ChopsticksFoodAction
rice -> 'рис';
ChopsticksFoodActionWord -> 'палочка';
ChopsticksFoodAction -> Verb ChopsticksFoodActionWord Prep rice|Verb Noun Prep ChopsticksFoodActionWord|Verb Prep ChopsticksFoodActionWord Noun|Verb ChopsticksFoodActionWord;
// End ChopsticksFoodAction

// 1
S -> Age+ interp(Situation_first.Age);
S -> WeightZn+ interp(Situation_first.WeightZn);
S -> PolName+ interp(Situation_first.PolName);
S -> med+ interp(Situation_first.med);

// 2
S -> Picture+ interp(Situation_first.Picture);
S -> Kvadrocopter+ interp(Situation_first.Kvadrocopter);
S -> Fines+ interp (Situation_first.Fines);

// 3
S -> reaction+ interp (Situation_first.reaction);
S -> CultureAction+ interp (Situation_first.CultureAction);
S -> location+ interp (Situation_first.location);

// 4
S -> garbage+ interp (Situation_first.garbage);
S -> urn+ interp (Situation_first.urn);

// 5
S -> tips+ interp (Situation_first.tips);
S -> foodAction+ interp (Situation_first.foodAction);

// 6
S -> tattoo+ interp (Situation_first.tattoo);

// 7
S -> name+ interp (Situation_first.name);
S -> getNameAction+ interp (Situation_first.getNameAction);
S -> kinship+ interp (Situation_first.kinship);

// 8
S -> PersonalSpace+ interp (Situation_first.PersonalSpace);

// 9
S -> ChopsticksFoodAction+ interp (Situation_first.ChopsticksFoodAction);