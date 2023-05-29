#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

//местонахождение
locationWord -> 'кафе'|'ресторан'|'столовая'|'кофейня'|'суши-бар'|'закусочная';
location -> Prep locationWord| Prep Adj locationWord;


//чаевые
Count -> AnyWord<wff=/[1-9]?[0-9]?[0-9]/>;
moneyWord -> 'деньги'|'чаевые'|'иена'|'чай';
tipsWord -> 'положить'|'оставить'|'дать';
tips -> tipsWord moneyWord| tipsWord Count moneyWord|tipsWord Prep moneyWord; 

//заслуга заведения
actionAdj -> 'хороший'|'вкусный'|'быстрый';
actionWord -> 'еда'|'обслуживание'|'атмосфера';
action -> actionAdj actionWord| Adj actionWord| actionAdj Noun;
//реакция окружающих
pron -> 'себя';
negative -> 'не';
reactionWord -> 'смотреть'|'шептаться'|'ругаться'|'вести'|'замечание'|'отказаться'|'оставить';
reaction -> Verb reactionWord|Adv reactionWord|Adv pron reactionWord|reactionWord|reactionWord moneyWord| reactionWord Prep moneyWord|negative Verb moneyWord|negative Verb|reactionWord;

S -> AnyWord* location interp (Situation_fifth.Location) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* action interp (Situation_fifth.Action);
S -> AnyWord* location interp (Situation_fifth.Location) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* action interp (Situation_fifth.Action) AnyWord* reaction interp (Situation_fifth.Reaction);
S -> AnyWord* location interp (Situation_fifth.Location) AnyWord* action interp (Situation_fifth.Action) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* reaction interp (Situation_fifth.Reaction);

S -> AnyWord* location interp (Situation_fifth.Location) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* action interp (Situation_fifth.Action);
S -> AnyWord* location interp (Situation_fifth.Location) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* action interp (Situation_fifth.Action) AnyWord* tips interp (Situation_fifth.Tips);
S -> AnyWord* location interp (Situation_fifth.Location) AnyWord* action interp (Situation_fifth.Action) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* tips interp (Situation_fifth.Tips);

S -> AnyWord* tips interp (Situation_fifth.Tips) AnyWord* location interp (Situation_fifth.Location) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* action interp (Situation_fifth.Action);
S -> AnyWord* tips interp (Situation_fifth.Tips) AnyWord* location interp (Situation_fifth.Location) AnyWord* action interp (Situation_fifth.Action) AnyWord* reaction interp (Situation_fifth.Reaction);
S -> AnyWord* tips interp (Situation_fifth.Tips) AnyWord* action interp (Situation_fifth.Action) AnyWord* location interp (Situation_fifth.Location) AnyWord* reaction interp (Situation_fifth.Reaction);

S -> AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* location interp (Situation_fifth.Location) AnyWord* action interp (Situation_fifth.Action);
S -> AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* action interp (Situation_fifth.Action) AnyWord* location interp (Situation_fifth.Location);
S -> AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* action interp (Situation_fifth.Action) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* location interp (Situation_fifth.Location);

S -> AnyWord* tips interp (Situation_fifth.Tips) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* location interp (Situation_fifth.Location) AnyWord* action interp (Situation_fifth.Action);
S -> AnyWord* tips interp (Situation_fifth.Tips) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* action interp (Situation_fifth.Action) AnyWord* location interp (Situation_fifth.Location);
S -> AnyWord* tips interp (Situation_fifth.Tips) AnyWord* action interp (Situation_fifth.Action) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* location interp (Situation_fifth.Location);

S -> AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* location interp (Situation_fifth.Location) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* action interp (Situation_fifth.Action);
S -> AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* location interp (Situation_fifth.Location) AnyWord* action interp (Situation_fifth.Action) AnyWord* tips interp (Situation_fifth.Tips);
S -> AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* action interp (Situation_fifth.Action) AnyWord* location interp (Situation_fifth.Location) AnyWord* tips interp (Situation_fifth.Tips);

S -> AnyWord* action interp (Situation_fifth.Action) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* location interp (Situation_fifth.Location) AnyWord* tips interp (Situation_fifth.Tips);
S -> AnyWord* action interp (Situation_fifth.Action) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* location interp (Situation_fifth.Location);
S -> AnyWord* action interp (Situation_fifth.Action) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* location interp (Situation_fifth.Location);
S -> AnyWord* action interp (Situation_fifth.Action) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* location interp (Situation_fifth.Location) AnyWord* reaction interp (Situation_fifth.Reaction);
S -> AnyWord* action interp (Situation_fifth.Action) AnyWord* location interp (Situation_fifth.Location) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* reaction interp (Situation_fifth.Reaction);
S -> AnyWord* action interp (Situation_fifth.Action) AnyWord* location interp (Situation_fifth.Location) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* tips interp (Situation_fifth.Tips);

S -> AnyWord* location interp (Situation_fifth.Location) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* reaction interp (Situation_fifth.Reaction);
S -> AnyWord* location interp (Situation_fifth.Location) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* tips interp (Situation_fifth.Tips);

S -> AnyWord* tips interp (Situation_fifth.Tips) AnyWord* location interp (Situation_fifth.Location) AnyWord* reaction interp (Situation_fifth.Reaction);
S -> AnyWord* tips interp (Situation_fifth.Tips) AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* location interp (Situation_fifth.Location);

S -> AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* tips interp (Situation_fifth.Tips) AnyWord* location interp (Situation_fifth.Location);
S -> AnyWord* reaction interp (Situation_fifth.Reaction) AnyWord* location interp (Situation_fifth.Location) AnyWord* tips interp (Situation_fifth.Tips);