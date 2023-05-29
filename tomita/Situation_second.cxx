#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

//квадрокоптер 
kvadro -> 'квадрокоптер';
//съёмка
Video -> 'видео'|'съёмка'|'фотография'|'фото';
VideoV -> 'снимать'|'фотографировать'|'поснимать'| 'пофотографировать';
Picture -> Prep Video|Verb Video|VideoV Noun|Verb VideoV;
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

S -> AnyWord* PP interp (Situation_second.Fines) AnyWord* Picture interp(Situation_second.Pictures) AnyWord* MM interp (Situation_second.Kvadrocopter);
S -> AnyWord* PP interp (Situation_second.Fines) AnyWord* MM interp (Situation_second.Kvadrocopter) AnyWord* Picture interp(Situation_second.Pictures);
S -> AnyWord* Picture interp(Situation_second.Pictures) AnyWord*  MM interp (Situation_second.Kvadrocopter) AnyWord* PP interp (Situation_second.Fines);
S -> AnyWord* Picture interp(Situation_second.Pictures) AnyWord* PP interp (Situation_second.Fines) AnyWord*  MM interp (Situation_second.Kvadrocopter);
S -> AnyWord* MM interp (Situation_second.Kvadrocopter) AnyWord* PP interp (Situation_second.Fines) AnyWord* Picture interp(Situation_second.Pictures);
S -> AnyWord* MM interp (Situation_second.Kvadrocopter) AnyWord* Picture interp(Situation_second.Pictures) AnyWord* PP interp (Situation_second.Fines);

S -> MM interp (Situation_second.Kvadrocopter) AnyWord* PP interp (Situation_second.Fines);
S -> PP interp (Situation_second.Fines) AnyWord* MM interp (Situation_second.Kvadrocopter);
