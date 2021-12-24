#pragma once
#include "..\Lab4\TQueue.h"

namespace ProjectWindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		int maxSize;
		int size;

		// Вероятности
		double p;
		double q;

		int popCount;
		int pushCount;

		TQueue<int>* pQueue;
		int centerX, centerY, width, height;
		Graphics^ gr;
		Random^ rndl;
		Pen^ myPen;
		Pen^ eraser;



	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label6;
		   

	public:
		MyForm(void)
		{
			InitializeComponent();
			
			gr = CreateGraphics();
			rndl = gcnew Random();

			myPen = gcnew Pen(Color::DarkViolet);
			myPen->Width = 10.0F;
			eraser = gcnew Pen(Color::White);
			eraser->Width = 10.0F;

			centerX = 110;
			centerY = 220;
			width = height = 180;

			popCount = pushCount = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Start;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Start
			// 
			this->Start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Start->Location = System::Drawing::Point(355, 208);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(121, 48);
			this->Start->TabIndex = 0;
			this->Start->Text = L"Старт";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &MyForm::Start_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(345, 15);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(83, 24);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"20";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(345, 62);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(83, 24);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"10";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(345, 112);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(83, 24);
			this->textBox3->TabIndex = 3;
			this->textBox3->Text = L"0,8";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(345, 159);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(83, 24);
			this->textBox4->TabIndex = 4;
			this->textBox4->Text = L"0,3";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(48, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(280, 22);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Максимальный размер очереди";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(61, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(267, 22);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Изначальный размер очереди";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(21, 112);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(307, 22);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Вероятность добавления элемента";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(23, 159);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(305, 22);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Вероятность извлечения элемента";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(61, 439);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(98, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Добавлено:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(268, 439);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(96, 20);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Извлечено:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(30, 287);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 31);
			this->label7->TabIndex = 11;
			this->label7->Text = L"0";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(155, 440);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(18, 20);
			this->label8->TabIndex = 12;
			this->label8->Text = L"0";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(360, 439);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(18, 20);
			this->label9->TabIndex = 13;
			this->label9->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 493);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Start);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void drawQueue() {
			int start = 360 * pQueue->getHead() / pQueue->getMaxSize();
			int finish = 360 * pQueue->getCount() / pQueue->getMaxSize();
			gr->DrawArc(myPen, centerX, centerY, width, height, start, finish);
		}

		void cleanQueue() {
			gr->DrawArc(eraser, centerX, centerY, width, height, 0, 360);
		}

		void start() {
			cleanQueue();
			drawQueue();
			label7->Text = Convert::ToString(size);
			Start->Text = "Стоп";
			timer1->Enabled = true;
		}

		void stop() {
			timer1->Enabled = false;
			cleanQueue();
			label7->Text = "0";
			label8->Text = "0";
			label9->Text = "0";
			Start->Text = "Старт";
			popCount = pushCount = 0;
		}

	private: System::Void Start_Click(System::Object^ sender, System::EventArgs^ e) {

		maxSize = Convert::ToInt32(textBox1->Text);
		size = Convert::ToInt32(textBox2->Text);
		p = Convert::ToDouble(textBox3->Text);
		q = Convert::ToDouble(textBox4->Text);

		pQueue = new TQueue<int>(maxSize);
		for (int i = 0; i < size; ++i)
			pQueue->push(i);


		if (Start->Text == "Старт")
			start();
		else
			stop();
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (rndl->NextDouble() <= p) {
			pQueue->push(0);
			pushCount++;
		}
		if (rndl->NextDouble() <= q) {
			pQueue->pop();
			popCount++;
		}
		size = pQueue->getCount();

		cleanQueue();
		drawQueue();
		label7->Text = Convert::ToString(size);
		label8->Text = Convert::ToString(pushCount);
		label9->Text = Convert::ToString(popCount);

		if (size == maxSize || size == 0)
			timer1->Enabled = false;
	}

	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
