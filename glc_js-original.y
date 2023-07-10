 %{
    // Includes em C/C++ e outras definições.
    #include <iostream>
    #include <string>
    #include <string.h>
    #include <map>
    #include <vector>

    using namespace std;

    struct Atributos {
    vector<string> c;
    };

    vector<string> concatena( vector<string> a, vector<string> b );
    vector<string> operator+( vector<string> a, vector<string> b );
    vector<string> operator+( vector<string> a, string b );
    string gera_label( string prefixo );
    vector<string> resolve_enderecos( vector<string> entrada );

    int linha = 1;
    int coluna = 1;

    // Tipo dos atributos: YYSTYPE é o tipo usado para os atributos.
    #define YYSTYPE Atributos

    void erro( string msg );
    void imprime_codigo( vector<string> codigo );

    // protótipo para o analisador léxico (gerado pelo lex)
    extern "C" int yylex();
    void yyerror( const char* );

    %}

    // Tokens
    %token	 _ID _NUM _STRING _LET _VAR _CONST _FOR _FUNCTION _IF _ELSE _INC _RETURN _SETA _FPSETA

    %start  S

    %left ','
    %right '=' _SETA  _FPSETA
    %nonassoc '<' '>' 
    %left '+' '-'
    %left '*' '/' '%'
    %left '[' '(' 
    %left _INC
    %left '.'
    %left ':'

    %%

    S : CMDs  
    ;

    CMDs : CMD CMDs            
        | DECL_VAR ';' CMDs    
        | DECL_FUN CMDs         
        |                     
        ;
        
    CMD : CMD_FOR
        | CMD_IF
        | E_V ';'
        | '{' CMD CMDs '}'      
        | '{' '}'      
        | ';'                  
        | _RETURN ';'
        | _RETURN EE ';'
        ;
        
    CMD_IF : _IF '(' E ')' CMD _ELSE CMD
        | _IF '(' E ')' CMD 
        ;
        
    CMD_FOR : _FOR '(' E_OPC ';' E_OPC ';' E_OPC ')' CMD     
            | _FOR '(' DECL_VAR ';' E_OPC ';' E_OPC ')' CMD     
            ;
            
    E_OPC : E_V
        |
        ;
    
    DECL_VAR : _LET VARs    
            | _VAR VARs   
            | _CONST CTEs   
            ;
            
    DECL_FUN : _FUNCTION _ID '(' ')' '{' CMDs '}' 
            | _FUNCTION _ID '(' PARAMs ')' '{' CMDs '}'
            ;
            
    PARAMs : PARAM ',' PARAMs
        | PARAM  
        ;

    PARAM : _ID '=' EE
        | _ID
        ;

    VARs : VAR ',' VARs     
        | VAR
        ;
                        
    VAR : _ID '=' EE    
        | _ID           
        ;
        
    CTEs : _ID '=' EE ',' CTEs
        | _ID '=' EE
        ;
    
    E_V : E ',' E_V
        | E
        ;
    
    EE : E
    | '{' '}'
    ;

    E : _ID '=' EE   
    | _ID _SETA EE
    | _ID _SETA '{' CMD CMDs '}'
    | '(' _FPSETA EE
    | '(' PARAMs _FPSETA EE
    | EE '.' _ID '=' EE
    | F '[' EE ']' '=' EE
    | EE '<' EE        
    | EE '*' EE         
    | EE '+' EE        
    | EE '-' EE        
    | EE '/' EE        
    | EE '>' EE        
    | EE '%' EE        
    | _INC EE
    | F
    ;

    F : _ID     
    | _NUM    
    | _STRING
    | '(' EE ')' 
    | F '(' ')'
    | F '[' EE ']'
    | F '(' ARGs ')'
    | F _INC
    | '[' ']'
    | '[' ARGs ']'
    | '{' CAMPOs '}'
    | EE '.' _ID
    | FUNC_ANON
    ;
    
    FUNC_ANON : _FUNCTION '(' ')' '{' CMDs '}' 
            | _FUNCTION '(' PARAMs ')' '{' CMDs '}'
            ;
            
            
    CAMPOs : CAMPOs ',' CAMPOs
        | _ID ':' EE
        ;
        

    ARGs : EE ',' ARGs
        | EE
        ;
    
    %%

    #include "lex.yy.c"

    void yyerror( const char* msg ) {
    cout << endl << "Erro: " << msg << endl
        << "Perto de : '" << yylval.c[0] << "'" <<endl
        << "Linha: " << linha << ", coluna: " << coluna <<endl;
    exit( 1 );
    }

    vector<string> concatena( vector<string> a, vector<string> b ) {
    a.insert( a.end(), b.begin(), b.end() );
    return a;
    }

    vector<string> operator+( vector<string> a, vector<string> b ) {
    return concatena( a, b );
    }

    vector<string> operator+( vector<string> a, string b ) {
    a.push_back( b );
    return a;
    }

    string gera_label( string prefixo ) {
    static int n = 0;
    return prefixo + "_" + to_string( ++n ) + ":";
    }

    vector<string> resolve_enderecos( vector<string> entrada ) {
    map<string,int> label;
    vector<string> saida;
    for( int i = 0; i < entrada.size(); i++ ) 
        if( entrada[i][0] == ':' ) 
            label[entrada[i].substr(1)] = saida.size();
        else
        saida.push_back( entrada[i] );
    
    for( int i = 0; i < saida.size(); i++ ) 
        if( label.count( saida[i] ) > 0 )
            saida[i] = to_string(label[saida[i]]);
        
    return saida;
    }

    void imprime_codigo( vector<string> codigo ) {
        for( int i = 0; i < codigo.size(); i++ )
            cout << codigo[i] << " ";
    }

    int main() {
    yyparse();
    cout << "Sintaxe ok" << endl;
    }