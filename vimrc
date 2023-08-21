" Plugins will be downloaded under the specified directory.
call plug#begin(has('nvim') ? stdpath('data') . '/plugged' : '~/.vim/plugged')

" Declare the list of plugins.
Plug 'morhetz/gruvbox'
Plug 'nathanaelkane/vim-indent-guides'
Plug 'scrooloose/nerdtree'
Plug 'Xuyuanp/nerdtree-git-plugin'
Plug 'sheerun/vim-polyglot'
Plug 'LunarWatcher/auto-pairs'
Plug '42Paris/42header'
" List ends here. Plugins become visible to Vim after this call.
call plug#end()

nnoremap <space> <Nop>

let g:indent_guides_enable_on_vim_startup	= 1
let g:AutoPairsShortcutToggle 				= '<C-p>'
let g:user42 								= 'fparreir'
let g:mail42 								= 'fparreir@student.42lisboa.com'
let mapleader								= " "

syntax 			on
filetype 		on
filetype plugin	on
filetype indent	on
set encoding	=utf-8
set updatetime	=300
set signcolumn	=yes
set tabstop		=4
set shiftwidth	=4
set tabstop		=4
set guicursor	=
set signcolumn	=yes
set undodir		=~/.vim/undodir
set nowrap
set nocompatible
set nobackup
set nowritebackup
set smartindent
set cursorline
set	cursorcolumn
set nu
set noswapfile
set nobackup
set undofile
set incsearch
set ignorecase
set smartcase

nnoremap o o <esc>
nnoremap O O <esc>
nnoremap q :wq!<CR>
nnoremap :q :q!<CR>

nnoremap <leader>n :NERDTreeToggle<CR>
nnoremap <leader>h :Stdheader<CR>
nnoremap <leader>v :vsplit<CR>
nnoremap <leader>s :split<CR>

" move focus on split windows
noremap <C-h> <c-w>h
noremap <C-j> <c-w>j
noremap <C-k> <c-w>k
noremap <C-l> <c-w>l
 
" resize split windows
noremap <c-up> <c-w>+
noremap <c-down> <c-w>-
noremap <c-left> <c-w>>
noremap <c-right> <c-w><
 
 
" STATUS LINE ------------------------------------------------------------ {{{

" Clear status line when vimrc is reloaded.
set statusline=

" Status line left side.
set statusline+=\ %F\ %M\ %Y\ %R

" Use a divider to separate the left side from the right side.
set statusline+=%=

" Status line right side.
set statusline+=\ ascii:\ %b\ hex:\ 0x%B\ row:\ %l\ col:\ %c\ percent:\ %p%%

" Show the status on the second to last line.
set laststatus=2

" }}} 
