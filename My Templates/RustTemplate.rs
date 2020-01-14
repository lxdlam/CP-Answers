use std::collections::LinkedList;
use std::io::stdin;
use std::str::FromStr;

struct Reader {
    tokens: LinkedList<String>,
    line: String,
}

impl Reader {
    pub fn new() -> Reader {
        Reader {
            tokens: LinkedList::new(),
            line: String::new(),
        }
    }

    fn read_line(&mut self) -> bool {
        self.line.clear();
        if let Ok(length) = stdin().read_line(&mut self.line) {
            if length == 0 {
                panic!("At the end of file!");
            }
        } else {
            panic!("At the end of file!");
        }
        self.tokens = self
            .line
            .split_whitespace()
            .map(|s| String::from(s))
            .collect();

        return true;
    }

    fn next_token(&mut self) -> String {
        if let Some(token) = self.tokens.pop_front() {
            token
        } else {
            self.read_line();
            self.next_token()
        }
    }

    pub fn next<T: FromStr>(&mut self) -> T {
        if let Ok(ret) = self.next_token().parse::<T>() {
            ret
        } else {
            panic!("Error on next!")
        }
    }
}
