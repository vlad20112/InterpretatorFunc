bison -d simple_example.y --xml="My_grammar.xml"
xsltproc /usr/share/bison/xslt/xml2xhtml.xsl My_grammar.xml > pict.html
flex simple_lexer.l
gcc -o simple_lang simple_example.tab.c lex.yy.c
rm My_grammar.xml 