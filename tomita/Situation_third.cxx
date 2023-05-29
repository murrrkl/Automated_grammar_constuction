#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

//местонахождение
locationWord -> 'кафе'|'кинотеатр'|'метро'|'спортзал'|'площадь'|'парк'|'ресторан'|'библиотека'|'магазин'|'супермаркет'|'автобус'|'музей'|'галлерея'|'выставка'|'столовая'|'кофейня'|'суши-бар'|'работа';
location -> Prep locationWord|Prep Adj locationWord;
//действие
actionVerb-> 'сморкаться'|'высморкаться';
actionWord -> 'платок'|'салфетка'|'насморк'; 
action -> Verb actionVerb|Verb actionWord| actionVerb Prep actionWord| actionVerb;
//реакция окружающих
reactionWord -> 'смотреть'|'шептаться'|'ругаться'|'кричать'|'закричать'|'накричать'|'замечание';
reaction -> Verb reactionWord|Adv reactionWord|reactionWord;

S -> AnyWord* action interp (Situation_third.Action) AnyWord* reaction interp (Situation_third.Reaction) AnyWord* location interp (Situation_third.Location);
S -> AnyWord* action interp (Situation_third.Action) AnyWord* location interp (Situation_third.Location) AnyWord* reaction interp (Situation_third.Reaction);

S -> AnyWord* reaction interp (Situation_third.Reaction) AnyWord* action interp (Situation_third.Action) AnyWord* location interp (Situation_third.Location);
S -> AnyWord* reaction interp (Situation_third.Reaction) AnyWord* location interp (Situation_third.Location) AnyWord* action interp (Situation_third.Action);

S -> location interp (Situation_third.Location) AnyWord* action interp (Situation_third.Action) AnyWord* reaction interp (Situation_third.Reaction);
S -> location interp (Situation_third.Location) AnyWord* reaction interp (Situation_third.Reaction) AnyWord* action interp (Situation_third.Action);

S -> action interp (Situation_third.Action) AnyWord* reaction interp (Situation_third.Reaction);
S -> reaction interp (Situation_third.Reaction) AnyWord* action interp (Situation_third.Action);