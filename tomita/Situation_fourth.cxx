#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

//местонахождение
locationWord -> 'кафе'|'кинотеатр'|'метро'|'спортзал'|'площадь'|'парк'|'ресторан'|'библиотека'|'магазин'|'супермаркет'|'автобус'|'музей'|'галлерея'|'выставка'|'столовая'|'кофейня'|'суши-бар'|'работа';
location -> Prep locationWord| Prep Adj locationWord;

//мусор
garbageWord -> 'сор'|'мусор'|'отходы';
garbageVerb -> 'выкинуть'|'выбросить'|'утилизировать';
garbage -> garbageVerb garbageWord| garbageVerb Noun| garbageWord;

//место для выброса мусора
urnNegative -> 'не';
urnVerbNegative -> 'нет'|'отсутствовать'|urnNegative Verb;
urnWord -> 'бак'|'урна'|'контейнер'|'ведро'|'корзина';
urn -> urnVerbNegative urnWord|urnVerbNegative urnWord Prep garbageWord| urnVerbNegative Adj urnWord| urnWord urnVerbNegative|urnWord Prep garbageWord urnVerbNegative| Adj urnWord urnVerbNegative|Adj urnWord| urnWord;

S -> location interp (Situation_fourth.Location) AnyWord* garbage interp (Situation_fourth.Garbage) AnyWord* urn interp (Situation_fourth.Urn);
S -> location interp (Situation_fourth.Location) AnyWord* urn interp (Situation_fourth.Urn) AnyWord* garbage interp (Situation_fourth.Garbage);
S -> AnyWord* urn interp (Situation_fourth.Urn) AnyWord* garbage interp (Situation_fourth.Garbage) AnyWord* location interp (Situation_fourth.Location);
S -> AnyWord* urn interp (Situation_fourth.Urn) AnyWord* location interp (Situation_fourth.Location) AnyWord* garbage interp (Situation_fourth.Garbage);

S -> AnyWord* garbage interp (Situation_fourth.Garbage) AnyWord* urn interp (Situation_fourth.Urn) AnyWord* location interp (Situation_fourth.Location);
S -> AnyWord* garbage interp (Situation_fourth.Garbage) AnyWord* location interp (Situation_fourth.Location) AnyWord* urn interp (Situation_fourth.Urn);

S -> garbage interp (Situation_fourth.Garbage) AnyWord* urn interp (Situation_fourth.Urn);
S -> urn interp (Situation_fourth.Urn) AnyWord* garbage interp (Situation_fourth.Garbage);