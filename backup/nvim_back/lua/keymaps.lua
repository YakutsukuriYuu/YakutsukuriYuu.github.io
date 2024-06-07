-- define common options
local opts = {
    noremap = true,      -- non-recursive
    silent = true,       -- do not show message
}

-----------------
-- Normal mode --
-----------------

-- Hint: see `:h vim.map.set()`
-- Better window navigation
vim.keymap.set('n', '<C-h>', '<C-w>h', opts)
vim.keymap.set('n', '<C-j>', '<C-w>j', opts)
vim.keymap.set('n', '<C-k>', '<C-w>k', opts)
vim.keymap.set('n', '<C-l>', '<C-w>l', opts)

-- Resize with arrows
-- delta: 2 lines
--vim.keymap.set('n', '<C-Up>', ':resize -2<CR>', opts)
--vim.keymap.set('n', '<C-Down>', ':resize +2<CR>', opts)
--vim.keymap.set('n', '<C-Left>', ':vertical resize -2<CR>', opts)
--vim.keymap.set('n', '<C-Right>', ':vertical resize +2<CR>', opts)

-----------------
-- Visual mode --
-----------------

-- Hint: start visual mode with the same area as the previous area and the same mode
vim.keymap.set('v', '<', '<gv', opts)

vim.keymap.set('v', '>', '>gv', opts)

-- 设置 timeoutlen 为 300 毫秒
vim.o.timeoutlen = 300

-- 绑定 jk 在插入模式下切换到正常模式
vim.api.nvim_set_keymap('i', 'jk', '<Esc>', { noremap = true, silent = true })


-- 绑定 Ctrl+W 保存并退出
vim.api.nvim_set_keymap('n', '<C-w>', ':wq<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('i', '<C-w>', '<Esc>:wq<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('v', '<C-w>', '<Esc>:wq<CR>', { noremap = true, silent = true })


-- 绑定 Shift+J 向下滚动自定义长度
vim.api.nvim_set_keymap('n', '<S-J>', ':normal! 5j<CR>', { noremap = true, silent = true })
-- 绑定 Shift+K 向下滚动自定义长度
vim.api.nvim_set_keymap('n', '<S-K>', ':normal! 5k<CR>', { noremap = true, silent = true })
-- 绑定 Command+Z (Ctrl+Z) 撤销功能
vim.api.nvim_set_keymap('n', '<C-z>', ':undo<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('i', '<C-z>', '<Esc>:undo<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('v', '<C-z>', '<Esc>:undo<CR>', { noremap = true, silent = true })

-- 绑定 Shift+小键盘上下左右键进行滚动
vim.api.nvim_set_keymap('n', '<S-Up>', ':normal! 5k<CR>', { noremap = true, silent = true })  -- 向上滚动 3 行
vim.api.nvim_set_keymap('n', '<S-Down>', ':normal! 5j<CR>', { noremap = true, silent = true })  -- 向下滚动 3 行
vim.api.nvim_set_keymap('n', '<S-Left>', ':normal! 5h<CR>', { noremap = true, silent = true })  -- 向左滚动 3 列
vim.api.nvim_set_keymap('n', '<S-Right>', ':normal! 5l<CR>', { noremap = true, silent = true })  -- 向右滚动 3 列
-- 绑定 Shift+小键盘上下左右键进行滚动
vim.api.nvim_set_keymap('i', '<S-Up>', '<Esc>:normal! 5k<CR>', { noremap = true, silent = true })  -- 向上滚动 3 行
vim.api.nvim_set_keymap('i', '<S-Down>', '<Esc>:normal! 5j<CR>', { noremap = true, silent = true })  -- 向下滚动 3 行
vim.api.nvim_set_keymap('i', '<S-Left>', '<Esc>:normal! 5h<CR>', { noremap = true, silent = true })  -- 向左滚动 3 列
vim.api.nvim_set_keymap('i', '<S-Right>', '<Esc>:normal! 5l<CR>', { noremap = true, silent = true })  -- 向右滚动 3 列

-- 设置 Option+小键盘方向键映射
vim.api.nvim_set_keymap('n', '<A-Right>', '<C-w>l', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<A-Left>', '<C-w>h', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<A-Down>', '<C-w>j', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<A-Up>', '<C-w>k', { noremap = true, silent = true })

-- 设置 Option+小键盘方向键映射
vim.api.nvim_set_keymap('i', '<A-Right>', '<Esc><C-w>l', { noremap = true, silent = true })
vim.api.nvim_set_keymap('i', '<A-Left>', '<Esc><C-w>h', { noremap = true, silent = true })
vim.api.nvim_set_keymap('i', '<A-Down>', '<Esc><C-w>j', { noremap = true, silent = true })
vim.api.nvim_set_keymap('i', '<A-Up>', '<Esc><C-w>k', { noremap = true, silent = true })

-- 使用 pbcopy 将文本复制到系统剪贴板
vim.api.nvim_set_keymap('v', '<leader>y', ':"+y', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<leader>y', ':"+y', { noremap = true, silent = true })

-- 确保 Neovim 使用系统剪贴板进行复制和粘贴
vim.opt.clipboard:append { 'unnamedplus' }





