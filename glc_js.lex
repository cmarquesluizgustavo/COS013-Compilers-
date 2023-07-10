%{
void acerta_coluna();
%}
D	[0-9]
L	[a-zA-Z_]

STRING_1   \'(\'\'|\\\'|[^\'])*\'
STRING_2   \"(\"\"|\\\"|[^\"])*\"
STRING     {STRING_1}|{STRING_2}

INT	{D}+
NUM	{INT}("."{INT})?([Ee]("+"|"-")?{INT})?
ID	{L}({L}|{D})*
FPSETA ")"[\n\t ]*"=>"

%%

" "		{ coluna++; }

"\t"	{ coluna += 4; }

"\n"    { linha++; coluna = 1; }

{STRING} 	{ acerta_coluna(); return _STRING; }
{NUM}   	{ acerta_coluna(); return _NUM; }
-{NUM}   	{ acerta_coluna(); return _NUM; }


"let"       { acerta_coluna(); return _LET; }
"var"       { acerta_coluna(); return _VAR; }
"const"     { acerta_coluna(); return _CONST; }
"for"       { acerta_coluna(); return _FOR; }
"if"        { acerta_coluna(); return _IF; }
"else"        { acerta_coluna(); return _ELSE; }
"function"  { acerta_coluna(); return _FUNCTION; }
"return"    { acerta_coluna(); return _RETURN; }
"while"     { acerta_coluna(); return _WHILE; }


"++"        { acerta_coluna(); return _INC_UM; }
"=>"        { acerta_coluna(); return _SETA; }
"+="        { acerta_coluna(); return _INC_A; }
"-="        { acerta_coluna(); return _DEC_A; }
"=="        { acerta_coluna(); return _IGUAL_A; }


{FPSETA}    { acerta_coluna(); return _FPSETA; }

{ID}		{ acerta_coluna(); return _ID; }

.       	{ acerta_coluna(); return *yytext; }

%%

void acerta_coluna() {
    coluna += strlen( yytext ); 
    yylval.c.clear();
    yylval.c.push_back( yytext );
    yylval.linha = linha;
    yylval.coluna = coluna;
}


