/* =====================================================
   HEROVERSE - DADOS DAS NOTÍCIAS
   Este arquivo guarda só o CONTEÚDO das matérias.
   Quem mostra as matérias na tela é o script.js.

   COMO ADICIONAR OU EDITAR UMA MATÉRIA:
   - Cada matéria tem um "id" (a palavra antes dos dois pontos).
     Esse id é usado no link do card: href="#noticia/ID"
   - titulo, subtitulo, categoria, data, dataTexto, imagem e imagemAlt
     são textos simples entre aspas.
   - conteudo é uma lista de textos. Cada texto vira um parágrafo.
     Se o texto começar com "## ", ele vira um subtítulo.

   AVISO: as matérias são ANÁLISES EDITORIAIS DEMONSTRATIVAS,
   escritas para este projeto acadêmico. As datas de publicação
   são fictícias.
   ===================================================== */

var noticias = {

  /* ---------- MATÉRIA 1 ---------- */
  "legado-herois-tecnologicos": {
    titulo: "O legado dos heróis tecnológicos",
    subtitulo: "Das armaduras aos assistentes de inteligência artificial, a tecnologia deixou de ser um simples acessório e passou a definir quem são esses personagens.",
    categoria: "CINEMA",
    data: "2026-11-24",
    dataTexto: "24 de novembro de 2026",
    imagem: "IMG/destaque-tecnologia.jpg",
    imagemAlt: "Armadura tecnológica de um herói fictício",
    conteudo: [
      "Quando Tony Stark apareceu nos quadrinhos da Marvel, em 1963, a ideia de um herói cuja força vinha da engenharia, e não de um acidente cósmico ou de uma origem sobrenatural, era uma novidade. O poder dele estava na mente de um inventor e na capacidade de transformar conhecimento em equipamento. Quando o personagem chegou ao cinema, em 2008, essa proposta ganhou o grande público e deu início ao universo cinematográfico da Marvel: um herói também podia nascer em uma oficina.",
      "## Quando o equipamento faz parte da identidade",
      "Batman, criado em 1939, é o outro grande exemplo. Sem superpoderes, ele depende de preparo físico, estratégia e de um arsenal que inclui o cinto de utilidades, veículos e a Batcaverna. Nos dois casos, a tecnologia não é só ferramenta: ela expressa a personalidade. A armadura de Stark mostra um homem que tenta controlar o medo com engenharia, enquanto o arsenal de Bruce Wayne revela alguém obcecado por prevenção e preparo.",
      "A fronteira entre humano e máquina também rende histórias poderosas. O Ciborgue, da DC, teve o corpo reconstruído com tecnologia e precisa conviver com a dúvida sobre o que ainda é humano nele. No cinema, o Visão nasce da combinação entre uma inteligência artificial e uma gema de poder cósmico, e passa a história inteira tentando entender o que significa sentir e escolher. Esses personagens levam para a ficção uma pergunta cada vez mais atual: onde termina a ferramenta e começa a pessoa?",
      "## Poder que também é vulnerabilidade",
      "A tecnologia, porém, traz fraquezas. Armaduras dependem de energia, podem falhar, ser copiadas ou cair em mãos erradas. Em Vingadores: Era de Ultron (2015), uma inteligência artificial criada para proteger o mundo decide que a melhor forma de fazer isso é eliminar a humanidade. A lição se repete em muitas histórias do gênero: a tecnologia amplifica as intenções de quem a controla, boas ou ruins.",
      "Esses heróis também funcionam como espelhos de cada época. Nos quadrinhos de 1963, Stark se feriu na Guerra do Vietnã; no filme de 2008, a origem foi atualizada para o Afeganistão. Hoje, as histórias dialogam com temas como vigilância, automação e inteligência artificial. Ao revisitar esses personagens, o cinema mostra o que cada geração espera, e teme, da tecnologia.",
      "No fim, a armadura mais interessante nunca é a mais resistente, e sim a que revela quem a veste. É por isso que os heróis tecnológicos continuam atuais: eles lembram que o futuro depende menos das máquinas que construímos e mais das escolhas que fazemos com elas."
    ]
  },

  /* ---------- MATÉRIA 2 ---------- */
  "heroi-simbolo-de-esperanca": {
    titulo: "O que torna um herói símbolo de esperança?",
    subtitulo: "Força impressiona, mas é o que o herói representa que faz as pessoas olharem para o céu em busca de uma razão para acreditar.",
    categoria: "PERSONAGENS",
    data: "2026-11-22",
    dataTexto: "22 de novembro de 2026",
    imagem: "IMG/destaque-esperanca.jpg",
    imagemAlt: "Herói protegendo pessoas em uma cidade iluminada",
    conteudo: [
      "Existem heróis fortes e existem heróis que viram símbolos. A diferença está no que as pessoas enxergam neles. O Superman, criado por Jerry Siegel e Joe Shuster e publicado pela primeira vez em 1938, surgiu em um período de crise econômica e apresentou um protetor dos mais fracos. Ele não era só alguém capaz de erguer um carro: era a promessa de que o poder poderia ser usado em favor dos outros.",
      "No cinema recente, o “S” do peito do personagem foi apresentado como um emblema que significa esperança. A ideia é simples e eficiente: o símbolo não diz o que o herói pode fazer, diz o que ele quer inspirar. O Capitão América, criado por Joe Simon e Jack Kirby em 1941, segue a mesma lógica. A força dele vem do soro, mas o que o torna símbolo são os ideais que defende.",
      "## Responsabilidade e inspiração",
      "O Homem-Aranha mostra outro caminho. Peter Parker é um jovem comum, com problemas de dinheiro, de tempo e de insegurança. Desde sua primeira aparição, em 1962, a história dele gira em torno da ideia de que ter poder traz responsabilidade. A esperança que ele inspira não vem de ser invencível, e sim de levantar depois de cair e continuar tentando.",
      "O sacrifício dá peso a esse simbolismo. Em Vingadores: Ultimato (2019), as despedidas de personagens como Tony Stark e Natasha Romanoff funcionam porque eles abrem mão de algo importante para que outras pessoas tenham futuro. Quando um herói perde alguma coisa ao agir, o público entende que a coragem dele tem custo, e isso a torna mais convincente.",
      "A coragem, nesse contexto, não é a ausência de medo. Os heróis que se tornam símbolos costumam hesitar, errar e sentir dúvida, mas agem mesmo assim. Esse comportamento cria identificação: quem assiste percebe que não precisa ter superpoderes para escolher fazer o certo em situações difíceis.",
      "Por isso esses personagens aparecem em camisetas, murais, campanhas e brincadeiras de criança. Eles se tornam uma linguagem comum para falar de justiça, solidariedade e perseverança. Um herói vira símbolo de esperança quando suas histórias lembram as pessoas de que ainda vale a pena acreditar no melhor de si mesmas."
    ]
  },

  /* ---------- MATÉRIA 3 ---------- */
  "herois-que-mudaram-o-genero": {
    titulo: "Heróis que mudaram o gênero",
    subtitulo: "De defensores perfeitos a figuras cheias de dúvidas, a trajetória dos super-heróis mostra como cada geração reinventou o que um herói pode ser.",
    categoria: "CURIOSIDADES",
    data: "2026-11-20",
    dataTexto: "20 de novembro de 2026",
    imagem: "IMG/destaque-legado.jpg",
    imagemAlt: "Silhueta de herói em uma paisagem cinematográfica",
    conteudo: [
      "Quando o Superman estreou, em 1938, ele estabeleceu uma fórmula que moldaria o gênero por décadas: um herói poderoso, com moral clara e inimigos que eram facilmente identificados como vilões. Esse modelo funcionou muito bem, mas deixava pouco espaço para conflitos internos e dilemas mais complexos.",
      "## A virada da Marvel",
      "No início dos anos 1960, a Marvel mudou essa abordagem. O Quarteto Fantástico, criado por Stan Lee e Jack Kirby em 1961, apresentava heróis que discutiam entre si e tinham problemas pessoais. O Homem-Aranha, de 1962, era um adolescente que se preocupava com dinheiro e com o que os outros pensavam dele. Os X-Men, de 1963, usavam a figura dos mutantes temidos pela sociedade como metáfora para o preconceito. Os super-heróis passaram a ser, também, pessoas.",
      "Nos anos 1980, o gênero ganhou tom mais sombrio e crítico. O Cavaleiro das Trevas (1986), de Frank Miller, imaginou um Batman velho e exausto, e Watchmen (1986-1987), de Alan Moore e Dave Gibbons, questionou o que aconteceria se heróis existissem de verdade em um mundo político e violento. As duas obras mostraram que histórias de super-heróis podiam falar de poder, justiça e moral com a seriedade de outros gêneros.",
      "O cinema seguiu um caminho parecido. Superman (1978) provou que era possível levar o gênero às telas com orçamento e respeito ao público. Batman Begins (2005) e O Cavaleiro das Trevas (2008) apostaram em um tom de thriller policial, e Homem de Ferro (2008) inaugurou a ideia de filmes conectados dentro de um mesmo universo, algo que mudou a forma de produzir e de acompanhar essas histórias.",
      "A representatividade também transformou o gênero. O Pantera Negra estreou nos quadrinhos em 1966, e o filme de 2018 foi indicado ao Oscar de melhor filme, algo inédito para uma produção de super-heróis. Logan (2017) e Coringa (2019) mostraram, por sua vez, que o gênero comporta dramas intimistas e personagens em situações de fragilidade.",
      "Cada uma dessas mudanças ampliou o público e a ambição das histórias. No fundo, o que evoluiu ao longo das décadas não foram só os poderes ou os uniformes, mas aquilo que esperamos de um herói: cada época pede um tipo de personagem que fale com seus próprios conflitos."
    ]
  },

  /* ---------- MATÉRIA 4 ---------- */
  "alem-dos-poderes": {
    titulo: "Muito além dos poderes: o que define um verdadeiro herói?",
    subtitulo: "Voar, lançar raios ou ter força sobre-humana impressiona, mas é a decisão de usar essa capacidade em favor dos outros que define um herói.",
    categoria: "MARVEL · PERSONAGENS",
    data: "2026-11-18",
    dataTexto: "18 de novembro de 2026",
    imagem: "IMG/noticia-heroi.jpg",
    imagemAlt: "Herói fictício em movimento entre edifícios",
    conteudo: [
      "Ter poderes e ser herói são coisas diferentes. O poder é uma capacidade; o heroísmo é uma escolha. Prova disso é que muitos dos personagens mais admiráveis dos quadrinhos e do cinema, como Batman, Gavião Arqueiro e Viúva Negra, têm habilidades limitadas quando comparados a deuses e alienígenas. O que os coloca na linha de frente é a decisão de agir quando seria mais fácil ficar de fora.",
      "## Escolhas e consequências",
      "As melhores histórias de heróis surgem quando eles precisam escolher entre duas opções que parecem certas. Em Capitão América: Guerra Civil (2016), inspirado em uma saga dos quadrinhos de 2006 e 2007, os personagens se dividem entre aceitar supervisão do governo ou preservar a liberdade de agir. Os dois lados têm argumentos sólidos, e é justamente isso que torna o conflito interessante: nenhum deles é um vilão.",
      "Escolher também significa assumir as consequências. Heróis que causam destruição, cometem erros ou falham em salvar alguém precisam lidar com o que fizeram. Quando a ficção mostra esse peso, ela lembra que ser herói não é só vencer a batalha, mas responder pelo que acontece depois dela.",
      "O altruísmo, por sua vez, está em agir sem esperar recompensa. No primeiro filme do Capitão América (2011), Steve Rogers é escolhido para receber o soro do supersoldado por seus valores, e não por sua força. A história deixa claro que o que o torna herói já existia antes de qualquer poder, e que o soro apenas ampliou o que ele era.",
      "Os vilões ajudam a mostrar essa diferença. Em séries como The Boys, que estreou em 2019, o Homelander tem poderes enormes e uma imagem pública de herói, mas falta a ele empatia e responsabilidade. A história usa esse contraste para provar que poder sem caráter é uma ameaça, não uma proteção.",
      "No fim, um verdadeiro herói é definido pelo que faz quando ninguém está olhando, quando o custo é alto e quando existe a opção de simplesmente ir embora. É por isso que as histórias mais memoráveis não se resumem a combates: elas giram em torno de decisões."
    ]
  },

  /* ---------- MATÉRIA 5 ---------- */
  "herois-continuam-relevantes": {
    titulo: "Por que os grandes heróis continuam relevantes?",
    subtitulo: "Criados há mais de oito décadas, personagens como Superman e Batman seguem ganhando novas versões porque cada geração encontra neles algo próprio.",
    categoria: "DC · UNIVERSO",
    data: "2026-11-16",
    dataTexto: "16 de novembro de 2026",
    imagem: "IMG/noticia-legado.jpg",
    imagemAlt: "Herói diante de uma cidade iluminada",
    conteudo: [
      "O Superman estreou em 1938, o Batman em 1939 e a Mulher-Maravilha em 1941. Mais de oitenta anos depois, os três continuam estrelando filmes, séries, jogos e quadrinhos. Poucos personagens da cultura popular atravessaram tanto tempo mantendo a capacidade de atrair novos fãs, e isso não acontece por acaso.",
      "A primeira razão é a identificação. Esses personagens falam de temas universais, como justiça, medo, perda e pertencimento. A história do Batman começa com a perda dos pais, algo que qualquer pessoa consegue compreender, mesmo sem nunca ter vestido uma capa. O Superman, um alienígena criado na Terra, representa a vivência de quem está entre dois mundos, e muita gente se reconhece nessa experiência.",
      "## Reinvenção constante",
      "A segunda razão é a capacidade de se reinventar. O Homem-Aranha já foi interpretado no cinema por Tobey Maguire (2002), Andrew Garfield (2012) e Tom Holland, a partir de 2016, e cada versão enfatizou aspectos diferentes do personagem. Nos quadrinhos, o surgimento de Miles Morales, em 2011, ampliou o legado do herói, e a animação Homem-Aranha: No Aranhaverso (2018) venceu o Oscar de melhor animação ao reunir várias versões do mesmo conceito.",
      "A terceira razão é a adaptação às mudanças sociais. Cada época reinterpreta seus heróis conforme seus próprios valores, preocupações e linguagens. Um personagem que fosse apenas uma peça de época teria desaparecido; os que sobrevivem são aqueles que permitem novas leituras sem perder o núcleo que os define.",
      "Há também o fator da memória afetiva. Pais que cresceram com esses heróis apresentam os personagens aos filhos, e as histórias passam a fazer parte de rituais familiares. Isso cria um público fiel e, ao mesmo tempo, uma pressão para que cada nova versão respeite o que torna o personagem querido.",
      "Relevância, porém, não é garantida. Um herói continua importante enquanto tem algo novo a dizer. Quando as histórias apenas repetem fórmulas, o interesse diminui. A longevidade desses personagens depende, portanto, de um equilíbrio delicado entre respeitar a tradição e ousar contar o que ainda não foi contado."
    ]
  },

  /* ---------- MATÉRIA 6 ---------- */
  "do-papel-para-as-telas": {
    titulo: "Do papel para as telas: como nasce uma adaptação",
    subtitulo: "Transformar páginas desenhadas em filmes e séries exige decisões sobre o que manter, o que cortar e o que reinventar.",
    categoria: "QUADRINHOS",
    data: "2026-11-14",
    dataTexto: "14 de novembro de 2026",
    imagem: "IMG/noticia-quadrinhos.jpg",
    imagemAlt: "Quadrinhos e materiais de produção",
    conteudo: [
      "Toda adaptação começa com uma pergunta: o que, exatamente, faz essa história funcionar? Os quadrinhos de super-heróis acumulam décadas de continuidade, centenas de edições e dezenas de personagens, enquanto um filme precisa contar algo completo em cerca de duas horas. Sem escolher o que é essencial, a adaptação corre o risco de ficar confusa ou superficial.",
      "## Do roteiro à tela",
      "O trabalho de roteiro costuma condensar arcos, combinar personagens e alterar a ordem dos acontecimentos. Capitão América: Guerra Civil (2016) é um bom exemplo: o filme se inspira na ideia central da saga dos quadrinhos, o conflito entre heróis sobre regulação e liberdade, mas reorganiza a trama e usa personagens que já tinham sido apresentados nos filmes anteriores.",
      "A discussão sobre fidelidade está sempre presente. Watchmen (2009), dirigido por Zack Snyder, reproduziu muitas composições visuais do material original, mas teve recepção dividida, o que mostra que seguir a obra à risca não garante o sucesso. Já a série The Boys, baseada na obra de Garth Ennis e Darick Robertson, alterou elementos da trama original para funcionar na televisão e conquistou o público, o que indica que mudanças bem pensadas também podem funcionar.",
      "O formato influencia muito essas decisões. Uma série tem mais espaço para desenvolver personagens e conflitos ao longo de vários episódios, enquanto um filme precisa de ritmo mais direto. Nos quadrinhos, o leitor controla o tempo de leitura; no audiovisual, quem controla o tempo é a montagem.",
      "## Duas linguagens visuais",
      "Quadrinhos e cinema contam histórias de formas diferentes. Nos quadrinhos, existem painéis, balões, onomatopeias e o espaço entre os quadros, no qual o leitor imagina o que aconteceu. No cinema, entram movimento, som, música e atuação. Homem-Aranha: No Aranhaverso (2018) misturou as duas linguagens ao incorporar recursos típicos dos quadrinhos, como textos de onomatopeia e pontos de impressão, e mostrou que a adaptação também pode celebrar a origem visual da história.",
      "Uma boa adaptação é, no fundo, uma tradução. Ela não precisa repetir cada detalhe, mas precisa preservar o espírito do que tornou a obra original especial e, ao mesmo tempo, aproveitar o que a nova mídia faz de melhor."
    ]
  },

  /* ---------- MATÉRIA 7 ---------- */
  "efeitos-visuais-mundos-impossiveis": {
    titulo: "Como os efeitos visuais criam mundos impossíveis",
    subtitulo: "Entre telas verdes, captura de movimento e explosões reais, o trabalho dos artistas de efeitos visuais sustenta boa parte da magia do cinema de heróis.",
    categoria: "CINEMA",
    data: "2026-11-12",
    dataTexto: "12 de novembro de 2026",
    imagem: "IMG/noticia-cinema.jpg",
    imagemAlt: "Cenário cinematográfico de ficção",
    conteudo: [
      "Filmes de super-heróis pedem coisas que a câmera não consegue registrar sozinha: pessoas voando, cidades inteiras sendo destruídas, criaturas gigantes e armas que não existem. Para tornar tudo isso crível, o cinema recorre a uma combinação de técnicas que vai muito além de simplesmente “colocar computação gráfica na tela”.",
      "## Do set ao computador",
      "Uma das bases é a composição digital. Muitas cenas são montadas em camadas: atores filmados diante de um fundo verde ou azul, cenários criados no computador, elementos reais de cena e iluminação ajustada para que tudo pareça ter sido registrado ao mesmo tempo. Se uma dessas camadas destoa, o público percebe, mesmo sem saber explicar por quê.",
      "A captura de movimento é outra ferramenta importante. Nela, o ator usa sensores ou é registrado por câmeras especiais, e sua atuação serve de base para um personagem digital. Mark Ruffalo, com o Hulk, e Josh Brolin, com Thanos, deram performances que orientaram os movimentos e as expressões de seus personagens. Em Guardiões da Galáxia, o Rocket nasceu da voz de Bradley Cooper e da referência de atuação de Sean Gunn no set.",
      "Os efeitos práticos continuam essenciais. Dublês, miniaturas, maquiagem, cenários construídos e explosões reais dão peso e textura à imagem. Em O Cavaleiro das Trevas (2008), por exemplo, a equipe virou um caminhão de verdade em uma rua de Chicago. Elementos reais costumam ajudar o público a sentir que aquilo está acontecendo de fato.",
      "A integração entre o real e o digital é o que torna o resultado convincente. Luz, sombra, reflexo e a forma como os personagens interagem com objetos precisam fazer sentido. Em Capitã Marvel (2019), o rejuvenescimento digital de Samuel L. Jackson para viver o Nick Fury dos anos 1990 mostrou como a tecnologia também pode servir para viajar no tempo sem que ninguém perceba o truque.",
      "No fim, os efeitos visuais valem pelo que fazem pela história. Uma batalha enorme só emociona quando o público se importa com quem luta, e um personagem digital só convence quando tem personalidade. Por trás de cada cena há centenas de artistas, e o melhor efeito costuma ser aquele que ninguém lembra de ter notado."
    ]
  },

  /* ---------- MATÉRIA 8 ---------- */
  "herois-trabalhando-juntos": {
    titulo: "Quando os heróis precisam trabalhar juntos",
    subtitulo: "Egos, métodos e objetivos diferentes fazem das equipes de heróis ótimos laboratórios de conflito, mas também de cooperação.",
    categoria: "EQUIPES · CURIOSIDADES",
    data: "2026-11-10",
    dataTexto: "10 de novembro de 2026",
    imagem: "IMG/noticia-equipe.jpg",
    imagemAlt: "Equipe de heróis fictícios em silhueta",
    conteudo: [
      "A Liga da Justiça estreou nos quadrinhos em 1960, e os Vingadores e os X-Men chegaram em 1963. Desde então, as equipes viraram uma das formas mais populares de contar histórias de super-heróis. A razão é simples: reunir personagens diferentes cria possibilidades que um herói sozinho dificilmente oferece.",
      "## Conflito como combustível",
      "O primeiro ganho é o conflito interno. Quando personalidades distintas precisam agir juntas, surgem choques de opinião, de método e de valores. Em Os Vingadores (2012), a disciplina de Steve Rogers entra em atrito com o estilo improvisado de Tony Stark, e a instabilidade do Hulk é uma ameaça constante. Antes de enfrentar o inimigo, a equipe precisa aprender a lidar consigo mesma.",
      "O segundo ganho é a complementaridade. Cada integrante traz uma habilidade que resolve um pedaço do problema: força, estratégia, tecnologia, mobilidade ou furtividade. Nas melhores histórias, nenhum herói resolve tudo sozinho, e a vitória depende de cada um assumir o papel em que é mais forte.",
      "A liderança é outro ponto interessante. O líder de uma equipe nem sempre é o mais poderoso; muitas vezes é quem consegue coordenar, ouvir e decidir sob pressão. Na Liga da Justiça, por exemplo, o Batman costuma ocupar o papel de estrategista justamente por não depender de superpoderes.",
      "A confiança sustenta tudo isso, e também é o que mais rende drama. Em Capitão América: Guerra Civil, a ruptura entre os Vingadores mostra como uma equipe pode se desfazer quando as pessoas deixam de acreditar umas nas outras. Já Guardiões da Galáxia segue o caminho oposto: um grupo de desajustados que, aos poucos, forma uma espécie de família.",
      "Por isso as equipes continuam funcionando. Elas lembram que ser forte não é o mesmo que ser suficiente, e que cooperar exige aceitar diferenças. O que torna uma equipe de heróis memorável não é a soma dos poderes, mas a forma como cada integrante aprende a confiar nos outros."
    ]
  },

  /* ---------- MATÉRIA 9 ---------- */
  "multiverso-versoes-do-heroi": {
    titulo: "Multiverso: por que tantas versões do mesmo herói?",
    subtitulo: "Realidades alternativas permitem contar histórias que nenhuma continuidade única comportaria, mas exigem cuidado para não esvaziar o que está em jogo.",
    categoria: "CURIOSIDADES · MULTIVERSO",
    data: "2026-11-08",
    dataTexto: "8 de novembro de 2026",
    imagem: "IMG/noticia-multiverso.jpg",
    imagemAlt: "Portais que representam diferentes universos",
    conteudo: [
      "Multiverso é a ideia de que existem várias realidades paralelas, cada uma com suas próprias versões de personagens e acontecimentos. Nos quadrinhos, o conceito é antigo: em 1961, a história “O Flash de Dois Mundos” apresentou ao público a existência de universos diferentes na DC, e desde então o recurso foi usado de várias formas.",
      "## Liberdade criativa",
      "A principal vantagem é a liberdade. Quando um autor quer experimentar, ele pode contar uma história em outro universo sem alterar a versão principal do personagem. A série What If…?, que a Marvel publica desde 1977, parte exatamente dessa premissa: e se um herói tivesse feito uma escolha diferente? Isso permite finais inesperados, mortes definitivas e experimentos que seriam arriscados na continuidade principal.",
      "O multiverso também facilita a reinvenção. No Aranhaverso, vários Homens-Aranha de mundos diferentes dividem a mesma história, e cada um mostra uma faceta do personagem. No cinema, Homem-Aranha: Sem Volta para Casa (2021) reuniu versões do herói interpretadas por Tobey Maguire, Andrew Garfield e Tom Holland, aproveitando a memória afetiva de diferentes gerações de fãs.",
      "## Os riscos",
      "O recurso tem custo. Se qualquer acontecimento pode ser desfeito ou refeito em outra realidade, o público pode perder a sensação de que as decisões importam. Há ainda o risco de a trama ficar confusa para quem está chegando agora e de o multiverso virar apenas uma desculpa para reunir rostos conhecidos. Curiosamente, a minissérie Crise nas Infinitas Terras (1985-1986) foi criada, em parte, para simplificar a confusão de universos que a própria DC tinha acumulado.",
      "O conceito chegou com força ao cinema e à televisão. Loki (2021) e Doutor Estranho no Multiverso da Loucura (2022) levaram a ideia para o universo cinematográfico da Marvel, e The Flash (2023) fez o mesmo no lado da DC. A Marvel chama esse conjunto de histórias de Saga do Multiverso.",
      "O multiverso funciona melhor quando cada versão diz algo novo sobre o personagem original. Mais versões não significam automaticamente mais histórias; significam mais perguntas, e é a qualidade das respostas que decide se o recurso enriquece o herói ou apenas multiplica o mesmo rosto."
    ]
  }

};
