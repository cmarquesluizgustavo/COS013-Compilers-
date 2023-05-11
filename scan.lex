%{
  #include <string>
  #include <stdio.h>

  string lexema;
%}

WS	        [ \t\n]
DIGITO      [0-9]
LETRA       [a-zA-Z]
FLOAT       {DIGITO}+("."{DIGITO}+)?([eE][+-]?{DIGITO}+)?
CARACTERE   ({LETRA}|{DIGITO}|"_"|"@")

FOR         [Ff][Oo][Rr]
IF          [Ii][Ff]
MAIG        >=
MEIG        <=
IG          ==
DIF         !=

COMENTARIO  ("//".*[^\n])|("/*"([^*]|[*][^/])*[*]?"/")

STRING      (\"(\\.|[^\"\n]|(\"\"))*\")|(\'(\\.|[^\'\n]|(\'\'))*\')
STRINGINI   \`(\\.|[^\`])*/\$
STRINGFIM   \}(\\.|[^\`])*\`
STRINGNOEXP \`(\\.|[^\`\{])*\`

ID          (("$"|("$@"((({LETRA}|"_")({CARACTERE})*))))((({LETRA}|"_")({CARACTERE})*))*)|(({LETRA}|"_")({CARACTERE})*)
EXPR        \$\{({ID})/\}

enum        TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _STRING2, _COMENTARIO, _EXPR };
INVALID_ID  ("@"+|("@"+({ID}"@"+))|(\$"@"+(\$)*)|({ID}\${ID}*)|({DIGITO}{ID}+)|({DIGITO}"@"+)|("@"+[_\$]+))

%%
    /* Padrões e ações. Nesta seção, comentários devem ter um tab antes */

{COMENTARIO}                { lexema = yytext; return _COMENTARIO; }

{FOR}                       { lexema = yytext; return _FOR;        }
{IF}                        { lexema = yytext; return _IF;         }
{WS}                       	{ /* ignora espaços, tabs e '\n' */    }

{ID}                        { lexema = yytext; return _ID;         }
{STRING}                    { std::string str(yytext); 
                              lexema = str.substr(1,str.length() -2 ); 
                              return _STRING;                      }


{INVALID_ID}                { printf("Erro: Identificador inválido: %s\n", yytext); }


{STRINGINI}                 { std::string str(yytext); lexema = str.substr(1,str.length() -1 ); return _STRING2; }
{EXPR}                      { std::string str(yytext); lexema = str.substr(2,str.length() -1 ); return _EXPR;    }
{STRINGFIM}                 { std::string str(yytext); lexema = str.substr(1,str.length() -2 ); return _STRING2; }
{STRINGNOEXP}               { std::string str(yytext); lexema = str.substr(1,str.length() -2 ); return _STRING2; }


{DIGITO}+                   { lexema = yytext; return _INT;   }
{FLOAT}                     { lexema = yytext; return _FLOAT; }
{MAIG}                      { lexema = yytext; return _MAIG;  }
{MEIG}                      { lexema = yytext; return _MEIG;  }
{IG}                        { lexema = yytext; return _IG;    }
{DIF}                       { lexema = yytext; return _DIF;   }

.                           { lexema = yytext; return *yytext;
                              /* Essa deve ser a última regra. 
                              Dessa forma qualquer caractere isolado 
                              será retornado pelo seu código ascii. */ }

%%

// Fim do arquivo
