#include "pdfitem.h"
#include <QPainter>

PdfItem::PdfItem()
{
    // setOpaquePainting(true); // Allows filling background
}

void PdfItem::setFilePath(const QString &path)
{
    if (m_filePath == path)
        return;
    m_filePath = path;
    m_doc.reset(Poppler::Document::load(m_filePath));
    if (m_doc)
        m_doc->setRenderHint(Poppler::Document::Antialiasing);
    update();
        emit pageCountChanged();
    emit filePathChanged();
}

int PdfItem::pageCount() const
{
    return m_doc ? m_doc->numPages() : 0;
}

void PdfItem::setPageNum(int num)
{
    if (m_pageNum == num)
        return;
    m_pageNum = num;
    update();
    emit pageNumChanged();
}

void PdfItem::paint(QPainter *painter)
{
    if (!m_doc || m_pageNum < 0 || m_pageNum >= m_doc->numPages())
        return;

    painter->fillRect(boundingRect(), Qt::gray); // <-- first!

    std::unique_ptr<Poppler::Page> page(m_doc->page(m_pageNum));
    if (!page)
        return;

    QSizeF pageSize = page->pageSizeF();     // PDF size in points (1/72")
    QSizeF itemSize = boundingRect().size(); // Item size in pixels

    // Calculate scale to fit while preserving aspect ratio
    qreal xScale = itemSize.width() / pageSize.width();
    qreal yScale = itemSize.height() / pageSize.height();
    qreal scale = std::min(xScale, yScale);

    // Render at a higher DPI for better quality (e.g., 96 * scale)
    const int baseDpi = 96; // higher than 72 gives better results
    int dpi = static_cast<int>(baseDpi * scale);

    QImage image = page->renderToImage(dpi, dpi);
    if (image.isNull())
        return;

    // Calculate target size with aspect ratio preserved
    QSizeF imageSize = image.size() / image.devicePixelRatioF();
    QSizeF targetSize = imageSize;

    // Scale down if image is larger than item
    if (targetSize.width() > itemSize.width() || targetSize.height() > itemSize.height())
    {
        qreal widthRatio = itemSize.width() / targetSize.width();
        qreal heightRatio = itemSize.height() / targetSize.height();
        qreal finalScale = std::min(widthRatio, heightRatio);
        targetSize *= finalScale;
    }

    // Center the image
    QPointF topLeft((itemSize.width() - targetSize.width()) / 2.0,
                    (itemSize.height() - targetSize.height()) / 2.0);
    QRectF targetRect(topLeft, targetSize);

    // Smooth scaling
    painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter->drawImage(targetRect, image);
    // painter->fillRect(boundingRect(), Qt::gray); // or Qt::gray
}

// void PdfItem::paint(QPainter* painter) {
//     if (!m_doc) return;
//     auto* page = m_doc->page(m_pageNum);
//     if (!page) return;
//     // QImage img = page->renderToImage(96, 96);
//      QImage img = page->renderToImage(200, 200); // Higher DPI
//     delete page;
//     if (!img.isNull())
//         painter->drawImage(boundingRect(), img);
// }

// void PdfItem::paint(QPainter *painter) {
//     if (!m_doc || m_pageNum < 0 || m_pageNum >= m_doc->numPages())
//         return;

//     auto page = m_doc->page(m_pageNum);
//     if (!page)
//         return;

//     QSizeF pageSize = page->pageSizeF();  // page size in points (1/72 inch)
//     QSizeF itemSize = boundingRect().size();

//     // Calculate scaling to maintain aspect ratio
//     qreal scaleX = itemSize.width() / pageSize.width();
//     qreal scaleY = itemSize.height() / pageSize.height();
//     qreal scale = std::min(scaleX, scaleY);

//     // DPI for Poppler renderToImage
//     int dpi = static_cast<int>(72 * scale);

//     // Render at scaled DPI
//     QImage image = page->renderToImage(dpi, dpi);
//     delete page;

//     if (image.isNull()) return;

//     // Calculate target image size (in device-independent pixels)
//     QSize imgSize = image.size() / image.devicePixelRatioF();
//     QSizeF targetSize(imgSize.width(), imgSize.height());

//     // Center image inside boundingRect
//     QPointF topLeft((itemSize.width() - targetSize.width()) / 2,
//                     (itemSize.height() - targetSize.height()) / 2);
//     QRectF targetRect(topLeft, targetSize);

//     painter->drawImage(targetRect, image);
// }
