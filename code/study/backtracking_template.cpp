void backtrack(/* estado atual, parâmetros do problema, resposta */) {
    // 1. CASO BASE (Objetivo atingido?)
    // [AJUSTE 1]: Quando salvar o caminho atual na resposta?
    // - Subsets: sempre (sem 'if').
    // - Permutations / Combinations / N-Queens: quando current.size() == alvo (e dá return).
    if (/* atingiu o objetivo */) {
        answer.push_back(current);
        return; 
    }

    // 2. LOOP DE ESCOLHAS (Quais são os próximos candidatos?)
    // [AJUSTE 2]: De onde o loop começa?
    // - Subsets / Combinations (ordem não importa): int i = start
    // - Permutations (ordem importa): int i = 0 (usando um vetor 'used')
    for (int i = start; i < candidates.size(); ++i) {
        
        // 3. PODA / VALIDAÇÃO (Esse candidato é válido agora?)
        // [AJUSTE 3]: Pular elementos já usados, duplicados ou posições inválidas (ex: N-Queens)
        if (/* candidato inválido ou já usado */) continue;

        // 4. FAZER -> EXPLORAR -> DESFAZER (O coração do backtracking)
        current.push_back(candidates[i]);          // Faz a escolha (Do)
        
        // [AJUSTE 4]: O que passar para o próximo nível?
        // - Sem repetir o mesmo elemento: i + 1
        // - Podendo repetir o mesmo elemento (ex: Combination Sum): i
        backtrack(/* próximo estado */);           // Explora (Recurse)
        
        current.pop_back();                        // Desfaz a escolha (Undo)
    }
}
