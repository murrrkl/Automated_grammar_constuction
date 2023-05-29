#encoding "utf-8"    // сообщаем парсеру о том, в какой кодировке написана грамматика
#GRAMMAR_ROOT S     // указываем корневой нетерминал грамматики

//действие
actionWord -> 'имя';
actionVerb -> 'назвать'|'звать';
actionVerbName -> 'дать';
action -> actionVerbName actionWord|actionWord|actionVerb;

//родство
kinship -> 'сын'|'дочь'|'малыш'|'племянник'|'племянница'|'сестра'|'брат'|'ребёнок'|'дочка'|'сынок';

//Имя
name -> AnyWord<gram="имя">;

//Исход ситуации
//штраф
Fine -> 'штраф';
FineVerb -> 'штрафовать'|'оштрафовать'|'заплатить'|'выплатить';
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

resultVerb -> 'изменить'|'сменить';
law -> 'суд';
result -> PP| resultVerb actionWord|Noun Prep law;

S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* action interp (Situation_seventh.Action) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* result interp (Situation_seventh.Result);
S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* action interp (Situation_seventh.Action) AnyWord* result interp (Situation_seventh.Result) AnyWord* kinship interp (Situation_seventh.Kinship);
S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* result interp (Situation_seventh.Result) AnyWord* action interp (Situation_seventh.Action) AnyWord* kinship interp (Situation_seventh.Kinship);
S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* result interp (Situation_seventh.Result) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* action interp (Situation_seventh.Action);
S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* result interp (Situation_seventh.Result) AnyWord* action interp (Situation_seventh.Action);
S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* action interp (Situation_seventh.Action) AnyWord* result interp (Situation_seventh.Result);

S -> AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* name interp (Situation_seventh.Name) AnyWord* action interp (Situation_seventh.Action) AnyWord* result interp (Situation_seventh.Result);
S -> AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* name interp (Situation_seventh.Name) AnyWord* result interp (Situation_seventh.Result) AnyWord* action interp (Situation_seventh.Action);
S -> AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* result interp (Situation_seventh.Result) AnyWord* name interp (Situation_seventh.Name) AnyWord* action interp (Situation_seventh.Action);
S -> AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* result interp (Situation_seventh.Result) AnyWord* action interp (Situation_seventh.Action) AnyWord* name interp (Situation_seventh.Name);
S -> AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* action interp (Situation_seventh.Action) AnyWord* result interp (Situation_seventh.Result) AnyWord* name interp (Situation_seventh.Name);
S -> AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* action interp (Situation_seventh.Action) AnyWord* name interp (Situation_seventh.Name) AnyWord* result interp (Situation_seventh.Result);

S -> AnyWord* action interp (Situation_seventh.Action) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* name interp (Situation_seventh.Name) AnyWord* result interp (Situation_seventh.Result);
S -> AnyWord* action interp (Situation_seventh.Action) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* result interp (Situation_seventh.Result) AnyWord* name interp (Situation_seventh.Name);
S -> AnyWord* action interp (Situation_seventh.Action) AnyWord* result interp (Situation_seventh.Result) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* name interp (Situation_seventh.Name);
S -> AnyWord* action interp (Situation_seventh.Action) AnyWord* result interp (Situation_seventh.Result) AnyWord* name interp (Situation_seventh.Name) AnyWord* kinship interp (Situation_seventh.Kinship);
S -> AnyWord* action interp (Situation_seventh.Action) AnyWord* name interp (Situation_seventh.Name) AnyWord* result interp (Situation_seventh.Result) AnyWord* kinship interp (Situation_seventh.Kinship);
S -> AnyWord* action interp (Situation_seventh.Action) AnyWord* name interp (Situation_seventh.Name) AnyWord* kinship interp (Situation_seventh.Kinship)AnyWord* result interp (Situation_seventh.Result);

S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* action interp (Situation_seventh.Action) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* result interp (Situation_seventh.Result);
S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* action interp (Situation_seventh.Action) AnyWord* result interp (Situation_seventh.Result) AnyWord* kinship interp (Situation_seventh.Kinship);
S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* result interp (Situation_seventh.Result) AnyWord* action interp (Situation_seventh.Action) AnyWord* kinship interp (Situation_seventh.Kinship);
S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* result interp (Situation_seventh.Result) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* action interp (Situation_seventh.Action);
S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* result interp (Situation_seventh.Result) AnyWord* action interp (Situation_seventh.Action);
S -> AnyWord* name interp (Situation_seventh.Name) AnyWord* kinship interp (Situation_seventh.Kinship) AnyWord* action interp (Situation_seventh.Action) AnyWord* result interp (Situation_seventh.Result);