" PLUGINS
call plug#begin('~/Users/mariyadancheva/.config/nvim/autoload')
Plug	'ellisonleao/gruvbox.nvim'	
Plug 'ludovicchabant/vim-gutentags'
Plug 'kien/ctrlp.vim'
Plug 	'jiangmiao/auto-pairs'
call plug#end()

" Configuration
let g:gutentags_enabled = 1
let g:gutentags_generate_on_write = 1
let g:gutentags_generate_on_empty_buffer = 1

" Key mappings for ctrlp
nmap <C-p> :CtrlP<CR>


let g:ctrlp_working_path_mode = 'ra'
" let g:ctrlp_user_command = ['.git', 'git --git-dir=%s/.git ls-files -co --exclude-standard']
" set path+=.

" W will expand to w
cmap W w
cmap Q q

let g:AutoPairsMapBS = 0
let g:auto_close = {'pairs': {'(': ')', '[': ']', '{': '}'}, 'filetypes': {'default': '/[^[:alnum:][:punct:]\s]/'}}
set autowrite
set clipboard=unnamed
set background=light
"colorscheme gruvbox
set shiftwidth=4
set tabstop=4
set number
syntax on
set colorcolumn=80
set cursorline
let mapleader = "`"

" For fold a whole paragraph type Leader + f
nnoremap <Leader>f zfap
nnoremap <Leader>w :w<CR>

" NORMINETTE--------------------------------------------------{{{{{{
function Norminette()
	!norminette %
endfunction
command Norminette call Norminette()

nnoremap <Leader>n :Norminette<CR>
"}}}}}}

" HIGHLIGHTING--------------------------------------------------{{{

" define line highlight color
highlight LineHighlight ctermbg=yellow guibg=yellow

" highlight the current line -> type Leader + l
nnoremap <silent> <Leader>l :call matchadd('LineHighlight', '\%'.line('.').'l')<CR>

" clear all the highlighted lines -> type Leader + c
nnoremap <silent> <Leader>c :call clearmatches()<CR>
" }}}

" TO UNBOLD TEXT-----------------------------------------------{{{
" Steve Hall wrote this function for me on vim@vim.org
" See :help attr-list for possible attrs to pass
function! Highlight_remove_attr(attr)
    " save selection registers
    new
    silent! put

    " get current highlight configuration
    redir @x
    silent! highlight
    redir END
    " open temp buffer
    new
    " paste in
    silent! put x

    " convert to vim syntax (from Mkcolorscheme.vim,
    "   http://vim.sourceforge.net/scripts/script.php?script_id=85)
    " delete empty,"links" and "cleared" lines
    silent! g/^$\| links \| cleared/d
    " join any lines wrapped by the highlight command output
    silent! %s/\n \+/ /
    " remove the xxx's
    silent! %s/ xxx / /
    " add highlight commands
    silent! %s/^/highlight /
    " protect spaces in some font names
    silent! %s/font=\(.*\)/font='\1'/

    " substitute bold with "NONE"
    execute 'silent! %s/' . a:attr . '\([\w,]*\)/NONE\1/geI'
    " yank entire buffer
    normal ggVG
    " copy
    silent! normal "xy
    " run
    execute @x

    " remove temp buffer
    bwipeout!

    " restore selection registers
    silent! normal ggVGy
    bwipeout!
endfunction
autocmd BufNewFile,BufRead * call Highlight_remove_attr("bold")
" }}}

"42 HEADER-----------------------------------------------------{{{
let g:user42 = 'mdanchev'
let g:mail42 = 'mdanchev@student.42lausanne.ch'
"}}}

"CSCOPES + CTAGS----------------------------------------------{{{	
if has("cscope")
        set csprg=/opt/homebrew/bin/cscope
        set csto=0
        set cst
        " add any database in current directory
        if filereadable("cscope.out")
            silent cs add cscope.out
        " else add database pointed to by environment
        elseif $CSCOPE_DB != ""
            silent cs add $CSCOPE_DB
        endif
endif

" Connect to cscope when vim starts, if cscope.out file exists, 
" or $CSCOPE_DB is defined.
function Connect_cscope_if()
    if filereadable('cscope.out')
        cscope add cscope.out
    elseif $CSCOPE_DB != ''
        cscope add $CSCOPE_DB
    endif
endfunction
autocmd VimEnter * call Connect_cscope_if()

" Reset cscope on save, if cscope.out file exists.
function Run_cscope_if()
    if filereadable('cscope.out')
        silent cscope reset
    endif
endfunction
autocmd BufWritePost *.c,*.h call Run_cscope_if()

" Run ctags and cscope on a fresh project == <Leader><F2>
function InitTags()
    silent cscope kill -1
    silent rm -f cscope.* tags
    silent !ctags -R . &
    silent !cscope -bcqR
    cscope add cscope.out
endfunction
command InitTags call InitTags()

nnoremap <Leader><F13> :InitTags<CR>
"}}} 

" FOLDING------------------------------------------------------{{{
" zo to open a single fold under the cursor.
" zc to close the fold under the cursor.
" zR to open all folds.
" zM to close all folds.

" This will enable code folding.
" Use the marker method of folding.
augroup filetype_vim
    autocmd!
    autocmd FileType vim setlocal foldmethod=marker
augroup END
"}}}

" PERSISTENT HISTORY--------------------------------------------{{{
if !isdirectory("/tmp/.vim-undo-dir")
    call mkdir("/tmp/.vim-undo-dir", "", 0700)
endif
set undodir=/tmp/.vim-undo-dir
set undofile
"}}}

