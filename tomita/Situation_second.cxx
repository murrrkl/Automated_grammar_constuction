#encoding "utf-8"
#GRAMMAR_ROOT S

Video -> 'видео'|'съёмка'|'фотография'|'фото';
VideoV -> 'снимать'|'фотографировать'|'поснимать'| 'пофотографировать';
Picture -> Prep Video|Verb Video|VideoV Noun|Verb VideoV;

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

S -> Picture interp(Situation_second.Picture) AnyWord* Fines interp(Situation_second.Fines) AnyWord* ;
S -> Fines interp(Situation_second.Fines) AnyWord* Picture interp(Situation_second.Picture) AnyWord* ;
