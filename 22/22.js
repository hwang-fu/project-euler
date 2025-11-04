import fs from "fs";

const names_txt = "names.txt";

const rdFile = (filename) => {
    try {
        const data = fs.readFileSync(filename, "utf-8");
        return data;
    }
    catch (err) {
        console.error(err);
    
    }
}

function main() {
    const names = rdFile(names_txt)
        .split(",")
        .map(name => name.replaceAll("\"", "").trim())
        .sort();
    const name_scores = names.map((name) => [...name].reduce((acc, ch) => acc + (ch.charCodeAt(0) - 'A'.charCodeAt(0) + 1), 0));
    const score = name_scores.reduce((acc, curr, idx) => acc + (curr * (idx + 1)), 0);
    console.log(score);
}

main();
