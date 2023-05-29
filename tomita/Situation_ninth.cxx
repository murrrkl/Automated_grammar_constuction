#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

//действия с палочками
rice -> 'рис';
actionWord -> 'палочка';
action -> Verb actionWord Prep rice|Verb Noun Prep actionWord|Verb Prep actionWord Noun|Verb actionWord; 

//реакция окружающих
negative -> 'не';
reactionWord -> 'смотреть'|'шептаться'|'ругаться'|'вести'|'замечание'|'выгнать'|'прогнать'|'запретить';
reaction -> Verb reactionWord|reactionWord Verb|Adv reactionWord|negative Verb|reactionWord;

S -> AnyWord* action interp (Situation_ninth.Action) AnyWord* reaction interp (Situation_ninth.Reaction);
S -> AnyWord* reaction interp (Situation_ninth.Reaction) AnyWord* action interp (Situation_ninth.Action);
