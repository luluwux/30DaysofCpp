# MarkHead Dönüştürücü Testi

Bu, paragraf (`<p>`) etiketleri için normal bir test metnidir. Programının bunu düzgün bir şekilde `<p>` etiketi içine alması gerekir.

Bu satır **kalın metin** içerir.
Bu satır *italik metin* içerir.
Bu satırda ikisi birden var: **Bu kalın** ve *bu da italik*.

[Bu normal bir linktir](https://github.com/luluwux).
Peki ya **[bu kalın bir link](https://github.com/luluwux)**?

---

## Özellik Testleri (H2)

Şimdi daha karmaşık senaryoları test edelim.

> Bu bir alıntı (blockquote) satırıdır. Programının bunu `<blockquote><p>...</p></blockquote>` olarak sarmalaması gerekir.

Aşağıdaki satır tam olarak `---` içerdiği için yatay çizgi (`<hr>`) olmalıdır:
---

Aşağıdaki satır ise bir paragraf olmalıdır, `<hr>` değil:
Bu satırın ortasında --- bir çizgi var.

### HTML Passthrough Testi (H3)

Bu bölüm, programının mevcut HTML'e dokunmama özelliğini test eder.

<div align="center">
    Programın bu satıra ve içindekilere dokunmaması, <p> etiketi eklememesi gerekir.
</div>

Aşağıdaki satırın başında boşluklar var ama hala HTML:
  <section>
     <h2>*Bu bir HTML H2 Başlığıdır*, Markdown değil!</h2>
     <p>Programın bu satırlara dokunmamasını bekliyoruz.</p>
  </section>

***

## Hata Ayıklama Testleri

Bu satırda boşluk olmadığı için başlık olmamalı:
#BaşlıkDeğil

Bu satır düz metindir.
*Bu da italik olmalı.*

Test bitti.