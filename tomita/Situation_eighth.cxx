#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

//местонахождения
locationWord -> 'кафе'|'кинотеатр'|'метро'|'спортзал'|'площадь'|'парк'|'ресторан'|'библиотека'|'магазин'|'супермаркет'|'автобус'|'музей'|'галлерея'|'выставка'|'столовая'|'кофейня'|'суши-бар'|'работа';
location -> Prep locationWord| Prep Adj locationWord;

//действие
actionVerb -> 'слушать'|'говорить'|'трогать'|'толкать'|'лезть'|'ругаться'|'скандалить'|'спорить'|'целоваться';
action -> actionVerb Prep Noun|Adv actionVerb| actionVerb Noun| actionVerb; 

//реакция окружающих
negative -> 'не';
reactionWord -> 'смотреть'|'шептаться'|'ругаться'|'вести'|'замечание'|'выгнать'|'прогнать'|'запретить';
reaction -> Verb reactionWord|reactionWord Verb|Adv reactionWord|negative Verb|reactionWord;

S -> location interp (Situation_eighth.Location) AnyWord* action interp (Situation_eighth.Action) AnyWord* reaction interp (Situation_eighth.Reaction);
S -> location interp (Situation_eighth.Location) AnyWord* reaction interp (Situation_eighth.Reaction) AnyWord* action interp (Situation_eighth.Action);

S ->  reaction interp (Situation_eighth.Reaction) AnyWord* location interp (Situation_eighth.Location) AnyWord* action interp (Situation_eighth.Action);
S ->  reaction interp (Situation_eighth.Reaction)  AnyWord* action interp (Situation_eighth.Action) AnyWord* location interp (Situation_eighth.Location);

S ->  action interp (Situation_eighth.Action) AnyWord* reaction interp (Situation_eighth.Reaction) AnyWord* location interp (Situation_sixth.Location);
S ->  action interp (Situation_eighth.Action) AnyWord* location interp (Situation_eighth.Location) AnyWord* reaction interp (Situation_eighth.Reaction);