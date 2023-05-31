#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

//Пол
PolName -> Word<kwtype=pol>;
//Мед. учреждение
hospitalW -> 'врач'|'доктор'|'лечение'|'госпиталь'|'больница'|'поликлиника'|'диета';
PP -> Prep hospitalW;
med -> Verb PP;
//Вес
WeightW -> 'сантиметр'|'килограмм';
WeightSokr -> 'см'|'кг';
Weight -> 'вес';
Count -> AnyWord<wff=/[1-9]?[0-9]?[0-9]/>;
WeightZn -> Count WeightW;
WeightZn -> Count WeightSokr;
WeightZn -> AnyWord Count WeightW;
WeightZn -> AnyWord Count WeightSokr;
WeightZn -> Adj Weight;
//Возраст
AgeW-> 'год'|'лет';
AgeNum -> AnyWord<wff=/[1-9]?[0-9]-?((ый)|(ть)|(ой))?/>;

Age -> AgeNum AgeW;

//квадрокоптер
kvadro -> 'квадрокоптер';
//съёмка
Video -> 'видео'|'съёмка'|'фотография'|'фото';
VideoV -> 'снимать'|'фотографировать'|'поснимать'| 'пофотографировать'; Picture -> Prep Video|Verb Video|VideoV Noun|Verb VideoV;
//штраф
Fine -> 'штраф';
FineVerb -> 'штрафовать'|'оштрафовать'|'заплатить';
//размер штрафа
Count -> AnyWord<wff=/[1-9]?[0-9]?[0-9]/>;
Currency -> 'иена';
CountZn -> Count Currency;
CountZnach -> Prep CountZn;
PP -> Verb Fine;
PP -> FineVerb CountZn;
PP -> FineVerb;
PP -> Verb CountZnach;
PP -> Verb CountZn;
MM-> Prep kvadro | Verb kvadro | kvadro;

//местонахождение
locationWord -> 'кафе'|'кинотеатр'|'метро'|'спортзал'|'площадь'|'парк'|'ресторан'|'библиотека'|'магазин'|'супермарк ет'|'автобус'|'музей'|'галлерея'|'выставка'|'столовая'|'кофейня'|'суши-бар'|'работа';
location -> Prep locationWord;
//действие - культура поведения
actionVerb-> 'сморкаться'|'высморкаться';
actionWord -> 'платок'|'салфетка'|'насморк';
action -> Verb actionVerb|Verb actionWord| actionVerb Prep actionWord| actionVerb; //реакция окружающих
reactionWord -> 'смотреть'|'шептаться'|'ругаться'|'кричать'|'закричать'|'накричать'|'замечание' | 'выгнать';
reaction -> Verb reactionWord|Adv reactionWord|reactionWord;

//мусор
garbageWord -> 'сор'|'мусор'|'отходы';
garbageVerb -> 'выкинуть'|'выбросить'|'утилизировать';
garbage -> garbageVerb garbageWord| garbageVerb Noun| garbageWord; //место для выброса мусора
urnNegative -> 'не';
urnVerbNegative -> 'нет'|'отсутствовать'|urnNegative Verb;
urnWord -> 'бак'|'урна'|'контейнер';
urn -> urnVerbNegative urnWord|urnVerbNegative urnWord Prep garbageWord|
urnVerbNegative Adj urnWord| urnWord urnVerbNegative|urnWord Prep garbageWord urnVerbNegative| Adj urnWord urnVerbNegative|Adj urnWord| urnWord;

//чаевые
Count -> AnyWord<wff=/[1-9]?[0-9]?[0-9]/>;
moneyWord -> 'деньги'|'чаевые'|'иена'|'чай';
tipsWord -> 'положить'|'оставить'|'дать';
tips -> tipsWord moneyWord| tipsWord Count moneyWord|tipsWord Prep moneyWord; //заслуга заведения
foodActionAdj -> 'хороший'|'вкусный'|'быстрый';
foodActionWord -> 'еда'|'обслуживание'|'атмосфера';
foodAction -> foodActionAdj foodActionWord| Adj foodActionWord| foodActionAdj Noun;

//наличе татуировки
tattooVerb -> 'изобразить'|'изображать'|'набить'|'наколоть';
tattoo -> 'тату'|'татуировка'| tattooVerb Noun;

//действие
getNameActionWord -> 'имя';
getNameActionVerb -> 'назвать'|'звать';
getNameActionVerbName -> 'дать';
getNameAction -> getNameActionVerbName getNameActionWord|getNameActionWord|getNameActionVerb; //родство
kinship ->
'сын'|'дочь'|'малыш'|'племянник'|'племянница'|'сестра'|'брат'|'ребёнок'|'дочка'|'сынок'; //Имя
name -> AnyWord<gram="имя">;

// личное пространство
PersonalSpaceVerb -> 'слушать'|'говорить'|'трогать'|'толкать'|'лезть'|'ругаться'|'скандалить'|'спорить'|'целоваться';
PersonalSpace -> PersonalSpaceVerb Prep Noun|Adv PersonalSpaceVerb| PersonalSpaceVerb Noun| PersonalSpaceVerb;

//действия с палочками
rice -> 'рис';
ChopsticksFoodActionWord -> 'палочка';
ChopsticksFoodAction -> Verb ChopsticksFoodActionWord Prep rice|Verb Noun Prep ChopsticksFoodActionWord|Verb Prep ChopsticksFoodActionWord Noun|Verb ChopsticksFoodActionWord;

// 1
S -> Age+ interp(Situation_first.Age);
S -> WeightZn+ interp(Situation_first.Ves);
S -> PolName+ interp(Situation_first.Pol);
S -> med+ interp(Situation_first.Med);

// 2
S -> Picture+ interp(Situation_first.Pictures);
S -> MM+ interp(Situation_first.Kvadrocopter);
S -> PP+ interp (Situation_first.Fines);

// 3
S -> reaction+ interp (Situation_first.Reaction);
S -> action+ interp (Situation_first.CultureAction);
S -> location+ interp (Situation_first.Location);

// 4
S -> garbage+ interp (Situation_first.Garbage);
S -> urn+ interp (Situation_first.Urn);

// 5
S -> tips+ interp (Situation_first.Tips);
S -> foodAction+ interp (Situation_first.FoodAction);

// 6
S -> tattoo+ interp (Situation_first.Tattoo);

// 7
S -> name+ interp (Situation_first.Name);
S -> getNameAction+ interp (Situation_first.getNameAction);
S -> kinship+ interp (Situation_first.Kinship);

// 8
S -> PersonalSpace+ interp (Situation_first.PersonalSpace);

// 9
S -> ChopsticksFoodAction+ interp (Situation_first.ChopsticksFoodAction);