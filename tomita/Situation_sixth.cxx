#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

//локация
locationWord -> 'баня'|'бассейн'|'сауна';
location -> Prep locationWord| Prep Adj locationWord|locationWord;

//наличе татуировки
tattooVerb -> 'изобразить'|'изображать'|'набить'|'наколоть';
tattoo -> 'тату'|'татуировка'| tattooVerb Noun;

//реакция окружающих
negative -> 'не';
reactionWord -> 'смотреть'|'шептаться'|'ругаться'|'вести'|'замечание'|'выгнать'|'прогнать'|'запретить';
reaction -> Verb reactionWord|reactionWord Verb|Adv reactionWord|negative Verb|reactionWord;

S -> location interp (Situation_sixth.Location) AnyWord* tattoo interp (Situation_sixth.Tattoo) AnyWord* reaction interp (Situation_sixth.Reaction);
S -> location interp (Situation_sixth.Location) AnyWord* reaction interp (Situation_sixth.Reaction) AnyWord* tattoo interp (Situation_sixth.Tattoo);

S ->  reaction interp (Situation_sixth.Reaction) AnyWord* location interp (Situation_sixth.Location) AnyWord* tattoo interp (Situation_sixth.Tattoo);
S ->  reaction interp (Situation_sixth.Reaction)  AnyWord* tattoo interp (Situation_sixth.Tattoo) AnyWord* location interp (Situation_sixth.Location);

S ->  tattoo interp (Situation_sixth.Tattoo) AnyWord* reaction interp (Situation_sixth.Reaction) AnyWord* location interp (Situation_sixth.Location);
S ->  tattoo interp (Situation_sixth.Tattoo) AnyWord* location interp (Situation_sixth.Location) AnyWord* reaction interp (Situation_sixth.Reaction);