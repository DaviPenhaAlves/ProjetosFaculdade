/* =====================================================
   HEROVERSE - JAVASCRIPT
   O JavaScript faz a página reagir aos cliques:
   1) abrir e fechar o menu no celular
   2) abrir a pesquisa e filtrar as notícias
   ===================================================== */


/* =====================================================
   PARTE 1 - MENU DO CELULAR
   ===================================================== */

// Pega os elementos do HTML pelo "id" de cada um
var menuToggle = document.getElementById('menuToggle');   // botão ☰
var mainNav = document.getElementById('mainNav');         // menu com os links

// Função que ABRE o menu
function abrirMenu() {
  mainNav.classList.add('open');                          // a classe "open" faz o menu aparecer (veja o CSS)
  menuToggle.setAttribute('aria-expanded', 'true');       // avisa leitores de tela que o menu está aberto
  menuToggle.setAttribute('aria-label', 'Fechar menu');
  menuToggle.textContent = '×';                           // troca o ☰ por ×
}

// Função que FECHA o menu
function fecharMenu() {
  mainNav.classList.remove('open');
  menuToggle.setAttribute('aria-expanded', 'false');
  menuToggle.setAttribute('aria-label', 'Abrir menu');
  menuToggle.textContent = '☰';
}

// Ao clicar no botão: se o menu está aberto, fecha; se está fechado, abre
function clicouNoBotaoMenu() {
  if (mainNav.classList.contains('open')) {
    fecharMenu();
  } else {
    abrirMenu();
  }
}

menuToggle.addEventListener('click', clicouNoBotaoMenu);


// Fecha o menu quando a pessoa clica em um dos links (útil no celular)
var linksDoMenu = mainNav.querySelectorAll('a');   // lista com todos os links do menu

for (var i = 0; i < linksDoMenu.length; i++) {
  linksDoMenu[i].addEventListener('click', fecharMenu);
}


/* =====================================================
   PARTE 2 - PESQUISA DAS NOTÍCIAS
   ===================================================== */

// Pega os elementos do HTML
var searchToggle = document.getElementById('searchToggle');   // botão da lupa
var searchBox = document.getElementById('searchBox');         // caixa de pesquisa
var searchInput = document.getElementById('searchInput');     // campo onde se digita
var closeSearch = document.getElementById('closeSearch');     // botão ×
var newsCards = document.querySelectorAll('.news-card');      // lista com os 6 cards de notícia
var noResults = document.getElementById('noResults');         // mensagem "nenhuma notícia encontrada"


// Clicou na lupa: se a pesquisa está escondida, mostra; se está aparecendo, esconde
function clicouNaLupa() {
  if (searchBox.hidden === true) {
    searchBox.hidden = false;                           // mostra a caixa
    searchToggle.setAttribute('aria-expanded', 'true');
    searchInput.focus();                                // já deixa o cursor no campo
  } else {
    searchBox.hidden = true;                            // esconde a caixa
    searchToggle.setAttribute('aria-expanded', 'false');
    searchInput.value = '';                             // limpa o campo
    filtrarNoticias('');                                // mostra todas as notícias de novo
  }
}

// Clicou no ×: esconde a pesquisa, limpa o campo e mostra todas as notícias de novo
function clicouEmFechar() {
  searchBox.hidden = true;
  searchToggle.setAttribute('aria-expanded', 'false');
  searchInput.value = '';
  filtrarNoticias('');
}

// Digitou algo no campo: filtra as notícias com o texto digitado
function digitouNoCampo() {
  // Se uma matéria estiver aberta, volta para a lista de notícias para mostrar o resultado
  if (artigoView.hidden === false) {
    window.location.hash = '#ultimas';
  }
  filtrarNoticias(searchInput.value);
}

searchToggle.addEventListener('click', clicouNaLupa);
closeSearch.addEventListener('click', clicouEmFechar);
searchInput.addEventListener('input', digitouNoCampo);


// Função que mostra só as notícias que combinam com o texto pesquisado
function filtrarNoticias(textoPesquisado) {
  // trim() tira espaços do começo e do fim; toLowerCase() deixa tudo em letras minúsculas
  var termo = textoPesquisado.trim().toLowerCase();
  var quantidadeVisivel = 0;   // conta quantas notícias aparecem

  // Passa por cada notícia, uma de cada vez
  for (var i = 0; i < newsCards.length; i++) {
    var card = newsCards[i];

    // Junta o texto que aparece no card com as palavras extras do atributo data-search do HTML
    var textoDoCard = card.innerText + ' ' + card.dataset.search;
    textoDoCard = textoDoCard.toLowerCase();

    // includes() verifica se o texto do card contém o que foi digitado
    if (textoDoCard.includes(termo)) {
      card.hidden = false;           // combina: mostra o card
      quantidadeVisivel = quantidadeVisivel + 1;
    } else {
      card.hidden = true;            // não combina: esconde o card
    }
  }

  // Se nenhuma notícia apareceu, mostra a mensagem "nenhuma notícia encontrada"
  if (quantidadeVisivel === 0) {
    noResults.hidden = false;
  } else {
    noResults.hidden = true;
  }
}


/* =====================================================
   PARTE 3 - LEITURA DAS MATÉRIAS
   Os dados das matérias ficam no arquivo noticias.js (variável "noticias").
   Aqui só mostramos a matéria certa na tela.

   Como funciona:
   - cada card tem um link, por exemplo: #noticia/alem-dos-poderes
   - quando o endereço (hash) muda, a função atualizarPagina() decide
     se mostra a página inicial ou uma matéria
   - por isso o botão "voltar" do navegador também funciona
   ===================================================== */

// Pega os elementos do HTML
var paginaInicial = document.getElementById('paginaInicial');   // banner, destaques e últimas notícias
var artigoView = document.getElementById('artigoView');         // área de leitura
var artigoCategoria = document.getElementById('artigoCategoria');
var artigoTitulo = document.getElementById('artigoTitulo');
var artigoSubtitulo = document.getElementById('artigoSubtitulo');
var artigoData = document.getElementById('artigoData');
var artigoImagem = document.getElementById('artigoImagem');
var artigoCorpo = document.getElementById('artigoCorpo');

var tituloDaPagina = document.title;   // guarda o título original da aba
var posicaoSalva = 0;                  // guarda até onde a página inicial estava rolada


// Mostra uma matéria na tela. O parâmetro "id" é o nome da matéria no noticias.js
function mostrarArtigo(id) {
  var noticia = noticias[id];

  // Se estiver saindo da página inicial, lembra a posição da rolagem para voltar no mesmo lugar
  if (paginaInicial.hidden === false) {
    posicaoSalva = window.scrollY;
  }

  // Preenche os campos com os dados da matéria
  artigoCategoria.textContent = noticia.categoria;
  artigoTitulo.textContent = noticia.titulo;
  artigoSubtitulo.textContent = noticia.subtitulo;
  artigoData.textContent = noticia.dataTexto;
  artigoData.setAttribute('datetime', noticia.data);
  artigoImagem.src = noticia.imagem;
  artigoImagem.alt = noticia.imagemAlt;

  // Monta o corpo do texto: limpa o que havia antes e cria um elemento para cada item da lista
  artigoCorpo.textContent = '';
  for (var i = 0; i < noticia.conteudo.length; i++) {
    var texto = noticia.conteudo[i];
    var elemento;

    if (texto.indexOf('## ') === 0) {
      // Texto que começa com "## " vira subtítulo
      elemento = document.createElement('h2');
      elemento.textContent = texto.substring(3);
    } else {
      // Os outros textos viram parágrafos
      elemento = document.createElement('p');
      elemento.textContent = texto;
    }

    artigoCorpo.appendChild(elemento);
  }

  // Esconde a página inicial e mostra a matéria
  paginaInicial.hidden = true;
  artigoView.hidden = false;
  document.title = noticia.titulo + ' | HeroVerse';

  // Vai para o topo da matéria ("instant" = sem a rolagem suave)
  window.scrollTo({ top: 0, behavior: 'instant' });
  artigoTitulo.focus({ preventScroll: true });   // ajuda leitores de tela a começar pelo título
}


// Mostra a página inicial. O parâmetro "hash" é o endereço atual (ex.: #ultimas)
function mostrarPaginaInicial(hash) {
  var estavaLendo = (artigoView.hidden === false);

  artigoView.hidden = true;
  paginaInicial.hidden = false;
  document.title = tituloDaPagina;

  // Só precisa ajustar a rolagem se o usuário estava lendo uma matéria
  if (estavaLendo) {
    var alvo = null;
    if (hash.length > 1) {
      alvo = document.getElementById(hash.substring(1));   // tira o # do começo
    }

    if (alvo) {
      alvo.scrollIntoView({ behavior: 'instant' });                  // vai até a seção do link (ex.: Notícias)
    } else {
      window.scrollTo({ top: posicaoSalva, behavior: 'instant' });   // volta para onde estava
    }
  }
}


// Decide o que mostrar de acordo com o endereço (hash) da página
function atualizarPagina() {
  var hash = window.location.hash;

  // "#noticia/".length é 9: o resto do endereço é o id da matéria
  if (hash.indexOf('#noticia/') === 0) {
    var id = hash.substring(9);

    if (noticias.hasOwnProperty(id)) {   // confere se existe uma matéria com esse id
      mostrarArtigo(id);
      return;
    }
  }

  // Qualquer outro endereço (ou matéria inexistente) mostra a página inicial
  mostrarPaginaInicial(hash);
}

window.addEventListener('hashchange', atualizarPagina);

// Executa uma vez ao abrir o site (para funcionar se alguém abrir o link de uma matéria direto)
atualizarPagina();
